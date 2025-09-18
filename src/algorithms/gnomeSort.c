#include <stdio.h>
#include "utilerias.h"
#include "gnomeSort.h"

void gnomeSort(int arr[], int n, SortStats *stats) {
    int pos = 0;
    while (pos < n) {
        // La primera parte de la condición no es una comparación de elementos
        if (pos == 0) {
            pos++;
            continue;
        }
        
        // Aquí se realiza la comparación clave
        //Comparación
        stats->comparisons++;

        if (arr[pos] >= arr[pos - 1]) {
            // Si está en orden, avanza
            pos++;
        } else {
            // Si no, intercambia y retrocede
            //Cambiar por swap
            int temp = arr[pos];
            arr[pos] = arr[pos - 1];
            arr[pos - 1] = temp;

            //Intercambio
            stats->swaps++;

            pos--;
        }
    }
}