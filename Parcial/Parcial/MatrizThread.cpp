#include <iostream>
#include <chrono>
#include <fstream>
#include <pthread.h>
#include <vector>
#include <cstdlib>
using namespace std;

class MatrizParalela {
private:
    vector<vector<int>> datos;
    int filas, columnas;
    int sumatotal;
    pthread_mutex_t mutex;

    struct HiloParams {
        int inicio;
        int fin;
        MatrizParalela* matrizPtr;
    };

    static void* sumarRango(void* arg) {
        HiloParams* params = (HiloParams*)arg;
        int sumaLocal = 0;

        for (int i = params->inicio; i < params->fin; ++i)
            for (int j = 0; j < params->matrizPtr->columnas; ++j)
                sumaLocal += params->matrizPtr->datos[i][j];

        pthread_mutex_lock(&params->matrizPtr->mutex);
        params->matrizPtr->sumatotal += sumaLocal;
        pthread_mutex_unlock(&params->matrizPtr->mutex);

        return NULL;
    }

public:
    MatrizParalela(int n, int m) : filas(n), columnas(m), sumatotal(0) {
        datos.resize(n, vector<int>(m));
        pthread_mutex_init(&mutex, NULL);
    }

    ~MatrizParalela() {
        pthread_mutex_destroy(&mutex);
    }

    void llenar(int limite = 100) {
        for (int i = 0; i < filas; ++i)
            for (int j = 0; j < columnas; ++j)
                datos[i][j] = rand() % limite;
    }

    int sumarConHilos(int numHilos = 4) {
        sumatotal = 0;
        pthread_t hilos[numHilos];
        HiloParams params[numHilos];

        int paso = filas / numHilos;

        for (int i = 0; i < numHilos; ++i) {
            int inicio = i * paso;
            int fin = (i == numHilos - 1) ? filas : inicio + paso;

            params[i] = {inicio, fin, this};
            pthread_create(&hilos[i], NULL, sumarRango, (void*)&params[i]);
        }

        for (int i = 0; i < numHilos; ++i) {
            pthread_join(hilos[i], NULL);
        }

        return sumatotal;
    }
};

int main() {
    srand(time(nullptr));

    int size;
    cout << "Ingrese la matriz maxima (tamaño de la matriz cuadrada): ";
    cin >> size;

    ofstream archivo("resultados.txt");
    archivo << "Tamaño de la matriz, Tiempo (nanosegundos)\n";

    for (int i = 1; i <= size; ++i) {
        MatrizParalela matriz(i, i);
        matriz.llenar();

        auto start = chrono::high_resolution_clock::now();
        int suma = matriz.sumarConHilos();
        auto end = chrono::high_resolution_clock::now();

        long long tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        cout << "Matriz de: " << i << "x" << i << endl;
        cout << "Suma total: " << suma << endl;
        cout << "Tiempo: " << tiempo << " nanosegundos\n" << endl;

        archivo << i << "," << tiempo << "\n";
    }

    archivo.close();
    return 0;
}