#include <iostream>
using namespace std;

const int MAX = 100; 

void llenarMatriz(int matriz[MAX][MAX], int n, int m, int limite = 100) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matriz[i][j] = rand() % limite;
        }
    }
}

void mostrarMatriz(int matriz[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matriz[i][j] << "  ";
        }
        cout << endl;
    }
}

int sumarMatriz(int matriz[MAX][MAX], int n, int m) {
    int suma = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            suma += matriz[i][j];
        }
    }
    return suma;
}

int main() {
    int n, m;
    cout << "ingrese el numero de filas (max " << MAX << "): ";
    cin >> n;
    cout << "ingrese el nuemro de columnas (max " << MAX << "): ";
    cin >> m;

    int matriz[MAX][MAX];

    llenarMatriz(matriz, n, m);
    mostrarMatriz(matriz, n, m);

    int suma = sumarMatriz(matriz, n, m);
    cout << "\nla suma es: " << suma << endl;

    return 0;
}
