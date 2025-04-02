#include <iostream>
#include <chrono>
#include <fstream> // Para escribir en archivos
using namespace std;

// Función para llenar el arreglo en orden descendente
void descendente(int resu[], int num) {
    for (int i = 0; i < num; i++) {
        resu[i] = num - i;
    }
}

// Función para ordenar el arreglo usando insert Sort
void insertSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Función para medir y mostrar el tiempo de ejecución del ordenamiento y guardarlo en un archivo
void rangoPruebas() {
    
    ofstream archivo("resultados.txt");
    archivo << "Tamaño del arreglo,Tiempo promedio (nanosegundos)\n";
    
    for (int i = 1; i <= 10000; i++) {
        int size = i;
        int* vec = new int[size];
        long long sumaTiempos = 0;
        
       
        descendente(vec, size);
        auto start = chrono::high_resolution_clock::now();
        insertSort(vec, size);
        auto end = chrono::high_resolution_clock::now();
        sumaTiempos += chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        
        
        long long tiempoPromedio = sumaTiempos /10000;
	//para redondear tiempos sino los numeros se hacen demasiados largos
        
        cout << i << " " << tiempoPromedio << endl;
        archivo << i << "," << tiempoPromedio << "\n";
        
        delete[] vec;
    }
    
    archivo.close();
}

int main() {
    rangoPruebas();
    return 0;
}

