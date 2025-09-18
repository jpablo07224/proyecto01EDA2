#include <stdio.h>
#include "insertionSort.h"
#include "utilerias.h"

void insertionSort(int a[], int n, SortStats *stats){
	int i,j,k; // Indices
	int aux; // Copia del valor

	for(i=1; i<n; i++){
		j=i;
		aux=a[i];
		//Comparación
		while (j>0 && aux < a[j-1]){
			stats->comparisons++;
            printf("Intercambiando %i [%i] por %i [%i]\n", a[j], j, a[j-1], j-1);
			//Intercambio
			stats->swaps++;
			a[j] = a[j-1];
			j--;
		}
		a[j]=aux;

	}
}