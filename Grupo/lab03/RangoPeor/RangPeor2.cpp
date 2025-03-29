#include <iostream>
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
    imprimir(arr,n);
}
void rangoPruebas(){
    for(int i = 1; i<10000; i++){
        int size = i;
        int vec[size];
        descendente(vec,size);
        cout<<"vector de tam: "<< i <<endl;
        imprimir(vec,size);
        cout<<"vector ordenado: ";
        insertionSort(vec,size);
        cout<<endl;
    }    
}
int main() {
    rangoPruebas();
    return 0;
}
