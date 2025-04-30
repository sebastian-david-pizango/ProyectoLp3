
#include <iostream>
#include <chrono>
#include <fstream>
#include <pthread.h>
using namespace std;

const int MAX = 1000;
int sumatotal = 0;
pthread_mutex_t mutex;
int matriz[MAX][MAX];

void llenarMatriz(int matriz[MAX][MAX], int n, int m, int limite = 100) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            matriz[i][j] = rand() % limite;
}

struct HiloParams {
    int inicio;
    int fin;
    int columnas;
};

void* sumarRango(void* arg) {
    HiloParams* params = (HiloParams*)arg;
    int sumaLocal = 0;

    for (int i = params->inicio; i < params->fin; ++i)
        for (int j = 0; j < params->columnas; ++j)
            sumaLocal += matriz[i][j];

    pthread_mutex_lock(&mutex);
    sumatotal += sumaLocal;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    int size;
    cout << "Ingrese la matriz maxima (tamaño de la matriz cuadrada): ";
    cin >> size;

    pthread_mutex_init(&mutex, NULL);
    ofstream archivo("resultados.txt");
    archivo << "Tamaño de la matriz, Tiempo (nanosegundos)\n";

    for (int i = 1; i <= size; ++i) {
        llenarMatriz(matriz, i, i);
        sumatotal = 0;

        pthread_t hilos[4];
        HiloParams params[4];

        int paso = i / 4;  // dividimos las filas en 4 partes

        // Crea 4 parámetros con rangos de 1/4
        params[0] = {0, paso, i};              // Primer cuarto
        params[1] = {paso, 2 * paso, i};       // Segundo cuarto
        params[2] = {2 * paso, 3 * paso, i};   // Tercer cuarto
        params[3] = {3 * paso, i, i};          // Cuarto hasta el final

        auto start = chrono::high_resolution_clock::now();

        // Crear los 4 hilos
        for (int j = 0; j < 4; ++j) {
            pthread_create(&hilos[j], NULL, sumarRango, (void*)&params[j]);
        }

        // Esperar a que los 4 hilos terminen
        for (int j = 0; j < 4; ++j) {
            pthread_join(hilos[j], NULL);
        }

        auto end = chrono::high_resolution_clock::now();
        long long tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        cout << "Matriz de: " << i << "x" << i << endl;
        cout << "Suma total: " << sumatotal << endl;
        cout << "Tiempo: " << tiempo << " nanosegundos\n" << endl;

        archivo << i << "," << tiempo << "\n";
    }

    archivo.close();
    pthread_mutex_destroy(&mutex);

    return 0;
}

