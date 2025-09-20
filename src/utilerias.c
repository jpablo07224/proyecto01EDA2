#include <stdio.h>
#include <stdlib.h> //malloc
#include "utilerias.h"

void swap(int *a, int *b) {
	int tempt = *a;
	*a = *b;
	*b = tempt;
}

void printArray(int a[], int n){
	for (int i = 0; i < n; i++){
		printf("%i ", a[i]);
	}
	printf("\n");
}

void printSubArray(int arr[],int low, int high){
    int i;
    printf("Sub array :  ");
	for (i=low; i <= high; i++)
		printf("%d ", arr[i]);
    printf("\n");
}

int* createRandomArray(int size) {
	//Arreglo dinámico
	int *listaNumeros = (int *) malloc(size * sizeof(int));

	//Verificar asignación de memoria
	if (listaNumeros == NULL)
		return NULL;

	//Creación
	for (int i = 0; i < size; i++) {
		listaNumeros[i] = rand() % (ALG_MAX_RANGE + 1);
	}
	
	return listaNumeros;
}

// Función auxiliar para obtener el valor máximo del arreglo
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}