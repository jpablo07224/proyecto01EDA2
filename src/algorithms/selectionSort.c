#include <stdio.h>
#include "selectionSort.h"
#include "utilerias.h"

void selectionSort(int arreglo[], int n, SortStats *stats){
	int indiceMenor, i, j; // indices

	for (i = 0; i < n - 1; i++){
		indiceMenor = i;
		for (j = i + 1; j < n; j++){
			//Comparación
			stats->comparisons++;
			if (arreglo[j] < arreglo[indiceMenor])
				indiceMenor = j;
		}
		if (i != indiceMenor){
			//Intercambio
			stats->swaps++;
            printf("Intercambiando %i [%i] por %i [%i]\n", arreglo[i], i, arreglo[indiceMenor], indiceMenor);
			swap(&arreglo[i],&arreglo[indiceMenor]);
            
		}
	}
}