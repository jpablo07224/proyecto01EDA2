#include <stdio.h>
#include "ordenamientos.h"
#include "utilerias.h"

//SelectionSort
void selectionSort(int arreglo[], int n){
	int indiceMenor, i, j;//indices
	for (i=0; i<n-1; i++){
		indiceMenor=i;
		for(j = i+1; j<n; j++){
			if(arreglo[j]<arreglo[indiceMenor])
				indiceMenor=j;
		}
		if (i!=indiceMenor){
            printf("Intercambiando %i [%i] por %i [%i]\n", arreglo[i], i, arreglo[indiceMenor], indiceMenor);
			swap(&arreglo[i],&arreglo[indiceMenor]);
            
		}
	}
}