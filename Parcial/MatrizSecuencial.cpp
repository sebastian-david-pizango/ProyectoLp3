#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdlib>  // para rand()
#include <ctime> // <--- Agrega esta línea para usar time()
using namespace std;

class Matriz {
private:
    vector<vector<int>> datos;
    int filas, columnas;

public:
    Matriz(int n, int m) : filas(n), columnas(m) {
        datos.resize(n, vector<int>(m)); //   ajusta el tamaño del vector principal (las filas) y además puede inicializar su contenido.
    }

    void llenar() {
        for (int i = 0; i < filas; ++i)
            for (int j = 0; j < columnas; ++j)
                datos[i][j] = rand() % 10;
    }

    void mostrar() const {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                cout << datos[i][j] << "  ";
            }
            cout << endl;
        }
    }

    int sumar() const {
        int suma = 0;
        for (int i = 0; i < filas; ++i)
            for (int j = 0; j < columnas; ++j)
                suma += datos[i][j];
        return suma;
    }
};
int main() {
    srand(time(nullptr)); // <-- Sembrar el generador de números aleatorios
    int size = 0;
    cout << "Ingrese la matriz maxima" << endl;
    cin >> size;

    ofstream archivo("resultados.txt");
    archivo << "Tamaño de la matriz,Tiempo promedio (nanosegundos)\n";

    for (int i = 1; i <= size; ++i) {
        Matriz matriz(i, i);
        matriz.llenar();

        auto start = chrono::high_resolution_clock::now();

        cout << "Matriz de: " << i << " x " << i << endl;
        //matriz.mostrar();

        int suma = matriz.sumar();

        auto end = chrono::high_resolution_clock::now();
        long long duracion = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        long long tiempoPromedio = duracion;

        cout << "\nLa suma es: " << suma << endl;
        cout << "Tiempo: " << tiempoPromedio <<" nanosegundos \n";
        
        archivo << i << "," << tiempoPromedio << "\n";
    }

    archivo.close();
    return 0;
}