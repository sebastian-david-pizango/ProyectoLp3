#include <iostream>
#include <chrono>
#include <fstream> // Para escribir en archivos
using namespace std;

const int MAX = 1000;

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
	int size = 0;
	cout << "ingrese la matriz maxima"<<endl;
	cin >> size;
	int i = 1;
	
	ofstream archivo("resultados.txt");
	archivo << "TamaC1o de la matriz,Tiempo promedio (nanosegundos)\n";

	while(i <= size) {
		long long sumaTiempos = 0; // Creo mi timer uvu

		int matriz[MAX][MAX];
		n = i, m = i;

		llenarMatriz(matriz, n, m);

		auto start = chrono::high_resolution_clock::now();

		cout<<"matriz de: "<<i<<" x "<<i<<endl;
		mostrarMatriz(matriz, n, m);

		int suma = sumarMatriz(matriz, n, m);

		auto end = chrono::high_resolution_clock::now();
		sumaTiempos += chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		long long tiempoPromedio = sumaTiempos /size;

		cout << "\nla suma es: " << suma << endl;
		cout << "Tiempo: "<<tiempoPromedio<<endl;

		archivo << i << "," << tiempoPromedio << "\n";
		i++;
	}
	archivo.close();
	return 0;
}
