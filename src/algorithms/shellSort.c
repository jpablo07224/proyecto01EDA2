#include <stdio.h>
#include "utilerias.h"
#include "shellSort.h"

void shellSort(int arr[], int n , SortStats *stats) {
    // Calcula el gap inicial usando la secuencia de Knuth
    int gap = 1;
    while (gap < n / 3) {
        gap = 3 * gap + 1;
    }

    // Comienza a ordenar con el gap más grande y lo reduce
    for (; gap > 0; gap /= 3) {
        // Realiza un ordenamiento por inserción para este gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            
            // Desplaza los elementos anteriores del gap que son mayores
            // Aquí contarías una comparación por cada vuelta del bucle
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                //Comparación
                stats->comparisons++;
                arr[j] = arr[j - gap];
                //Intercambio
                stats->swaps++;
            }
            //Comparación
            stats->comparisons++; // La comparación final que falla
            
            arr[j] = temp;
        }
    }
}