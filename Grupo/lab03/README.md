# Carpeta de la actividad del Laboratio 03 de LP3

En el directorio se encuentran dos carpetas una que se llama "Peor" que es el codigo hecho en el laboratorio y "RangoPeor" que es la carpeta ya con la simulación.

## Participantes:
- Sebastian David
- Joel Choquepata
- Franco Rojas
- Joaquín Torres

# Codigo fuente

Acá las partes del código fuente del ordenamiento y de la creación de arrays del 1 hasta el 10000 en el peor caso

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

## Codigo de creacion de arrays en el peor caso

void descendente(int resu[], int num) {

    for (int i = 0; i < num; i++) {

        resu[i] = num - i;

    }
}

# Commits

## Peor caso y ordenamiento

- El código hecho en clase y el código del ordenamiento de GeeksforGeeks "https://www.geeksforgeeks.org/insertion-sort-algorithm/?ref=gcse_outind"

Commit 1 y 2: https://github.com/sebastian-david-pizango/ProyectoLp3/commit/b0cf7d80db6ab3e97bfe7ffc6ff0b95b038d2012

## Medida de tiempo
- Agregado de la medida de tiempo

Commit 3: https://github.com/sebastian-david-pizango/ProyectoLp3/commit/ca754d80c0a073085117dabcbc02cd2712298dfd


-
