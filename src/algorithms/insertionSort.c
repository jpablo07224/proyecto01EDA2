#include <stdio.h>
#include "ordenamientos.h"
#include "utilerias.h"

//InsertionSort
void insertionSort(int a[], int n){
	int i,j,k;//Indices
	int aux;//Copia del valor

	for(i=1; i<n; i++){
		j=i;
		aux=a[i];
		while (j>0 && aux < a[j-1]){
            printf("Intercambiando %i [%i] por %i [%i]\n", a[j], j, a[j-1], j-1);
			a[j] = a[j-1];
			j--;
		}
		a[j]=aux;

	}
}