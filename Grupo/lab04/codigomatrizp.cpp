#include <iostream>
#include <chrono>
#include <fstream>  // Para escribir en archivos
#include <pthread.h>  // Agregado para manejar hilos
using namespace std;

const int MAX = 1000;  // Tamaño máximo de la matriz

// Variable global que se actualizará en la función sumarMatriz
int variable = 0;
pthread_mutex_t mutex;  // Mutex para proteger el acceso a la variable compartida

// Función que llena la matriz con números aleatorios
void llenarMatriz(int matriz[MAX][MAX], int n, int m, int limite = 100) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matriz[i][j] = rand() % limite;  // Llena la matriz con valores aleatorios
        }
    }
}

// Función que muestra la matriz en consola (opcional, para verificar)
void mostrarMatriz(int matriz[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matriz[i][j] << "  ";  // Imprime cada valor de la matriz
        }
        cout << endl;
    }
}

// Estructura que se pasará a los hilos con los parámetros
struct HiloParams {
    int* fila;  // Fila específica que el hilo debe procesar
    int m;      // Número de columnas
};

// Función que será ejecutada por cada hilo para sumar una fila de la matriz
void* sumarFila(void* arg) {
    HiloParams* params = (HiloParams*)arg;  // Convertir el argumento a HiloParams
    int* fila = params->fila;  // Fila que el hilo debe sumar
    int m = params->m;         // Número de columnas

    int sumaFila = 0;  // Suma local para la fila

    // Sumar los elementos de la fila
    for (int j = 0; j < m; ++j) {
        sumaFila += fila[j];  // Acumulamos la suma de la fila
    }

    // Usamos el mutex para proteger la variable global `variable` al actualizarla
    pthread_mutex_lock(&mutex);
    variable += sumaFila;  // Sumamos el resultado local al global
    pthread_mutex_unlock(&mutex);

    return NULL;  // Terminamos la ejecución del hilo
}

// Función principal que maneja la ejecución de los hilos y la medición de tiempos
int main() {
    int n, m;
    int size = 0;
    cout << "Ingrese la matriz maxima (tamaño de la matriz cuadrada): ";
    cin >> size;

    pthread_mutex_init(&mutex, NULL);  // Inicializamos el mutex

    pthread_t hilos[MAX];  // Array de hilos
    int matriz[MAX][MAX];  // Matriz que vamos a llenar y procesar

    int i = 1;

    ofstream archivo("resultados.txt");  // Archivo para guardar los resultados
    archivo << "Tamaño de la matriz, Tiempo promedio (nanosegundos)\n";

    // Bucle principal que ejecuta los cálculos para diferentes tamaños de matrices
    while (i <= size) {
        long long sumaTiempos = 0;  // Variable para acumular los tiempos de cada ejecución

        n = i, m = i;  // Definimos las dimensiones de la matriz

        llenarMatriz(matriz, n, m);  // Llenamos la matriz con valores aleatorios

        auto start = chrono::high_resolution_clock::now();  // Inicio de la medición del tiempo

        cout << "Matriz de: " << i << " x " << i << endl;
        //mostrarMatriz(matriz, n, m);  // Opcional: Mostrar la matriz generada

        // Creamos y ejecutamos un hilo por fila de la matriz
        for (int j = 0; j < n; j++) {
            // Preparamos los parámetros para el hilo
            HiloParams* params = new HiloParams;
            params->fila = matriz[j];  // Pasamos la fila j de la matriz
            params->m = m;  // Pasamos el número de columnas

            pthread_create(&hilos[j], NULL, sumarFila, (void*)params);  // Crear el hilo para procesar la fila
        }

        // Esperamos a que todos los hilos terminen
        for (int j = 0; j < n; j++) {
            pthread_join(hilos[j], NULL);  // Esperamos que el hilo j termine
        }

        auto end = chrono::high_resolution_clock::now();  // Fin de la medición del tiempo
        sumaTiempos += chrono::duration_cast<chrono::nanoseconds>(end - start).count();  // Acumulamos el tiempo

        long long tiempoPromedio = sumaTiempos / size;  // Calculamos el tiempo promedio

        cout << "\nLa suma es: " << variable << endl;
        cout << "Tiempo: " << tiempoPromedio << " nanosegundos" << endl;

        archivo << i << "," << tiempoPromedio << "\n";  // Guardamos los resultados en el archivo
        i++;
    }

    archivo.close();  // Cerramos el archivo

    pthread_mutex_destroy(&mutex);  // Destruimos el mutex

    return 0;
}
