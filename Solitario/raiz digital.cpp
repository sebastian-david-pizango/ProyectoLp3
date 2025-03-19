/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

// Función para calcular la raíz digital de un número
int raizDigital(int arr[], int size) {
    int suma = 0;
    for (int i = 0; i < size; i++) {
        suma += arr[i];
    }
    
    while (suma >= 10) { // Repetir hasta que el número sea de un solo dígito
        int temp = 0;
        while (suma > 0) {
            temp += suma % 10; // Extraer el último dígito y sumarlo
            suma /= 10; // Eliminar el último dígito
        }
        suma = temp; // Actualizar suma con la nueva suma de dígitos
    }
    return suma;
}

int main() {
    int numero;
    while (true) {
        cin >> numero;
        if (numero == 0) break; // Condición de salida
        
        // Convertir número a array de dígitos
        int digitos[10], size = 0, temp = numero;
        while (temp > 0) {
            digitos[size++] = temp % 10;
            temp /= 10;
        }
        
        if (size == 1) {
            cout << numero << endl;
        } else {
            cout << raizDigital(digitos, size) << endl;
        }
    }
    return 0;
}