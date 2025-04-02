# Carpeta de la actividad del Laboratio 03 de LP3

En el directorio se encuentran dos carpetas una que se llama "Peor" que es el codigo hecho en el laboratorio y "RangoPeor" que es la carpeta ya con la simulación.

## Participantes:
- Sebastian David
- Joel Choquepata
- Franco Rojas
- Joaquín Torres

#Codigo fuente

Acá las partes del código fuente del ordenamiento y de la creación de arrays del 1 hasta el 10000

## Codigo fuente del ordenamiento

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

