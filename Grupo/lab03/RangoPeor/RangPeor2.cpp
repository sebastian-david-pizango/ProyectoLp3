#include <iostream>
#include <chrono>  // Para medir el tiempo
using namespace std;

// Función para imprimir el arreglo
void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Función para llenar el arreglo en orden descendente
void descendente(int resu[], int num) {
    for (int i = 0; i < num; i++) {
        resu[i] = num - i;
    }
}

// Función para ordenar el arreglo usando Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Mover los elementos de arr[0..i-1] que son mayores que key
        // a una posición adelante de su posición actual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Función para medir y mostrar el tiempo de ejecución del ordenamiento
void rangoPruebas(){
    for(int i = 1; i <= 10000; i++){
        int size = i;
        int vec[size];
        descendente(vec, size);
        
        cout << "Vector de tamaño: " << i << endl;
        imprimir(vec, size);

        // Medir el tiempo de ejecución del ordenamiento
        auto start = chrono::high_resolution_clock::now();
        insertionSort(vec, size);
        auto end = chrono::high_resolution_clock::now();
        
        // Calcular la duración en nanosegundos
        chrono::duration<long long, std::nano> duration = end - start;
        
        cout << "Vector ordenado: ";
        imprimir(vec, size);
        
        // Imprimir el tiempo que tardó el ordenamiento en nanosegundos
        cout << "Tiempo: " << duration.count() << " nanosegundos" << endl;
        cout << endl;
    }
}

int main() {
    rangoPruebas();
    return 0;
}
