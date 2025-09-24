-/*
-       Autor:
-       Editores: Muñoz Peña Juan Pablo
-
-       Fecha de última modificación: Martes 23 de Septiembre
-
-       Proposito: Funciones de apoyo, tales como intercambio, creación de arreglos, obtener máximo, etc.
-
-*/

#include <stdio.h>
#include <stdlib.h> //malloc
#include "utilerias.h"
#include "algoritmos.h"

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

//Menú ejecución del algoritmo y tamaño
void ejecutarAlgoritmo(int lista[], int size, int algorithm, SortStats stats, SortStats *avgStats) {
	switch (algorithm) {
		case 0:
			insertionSort(lista, size, &stats);
		break;
		case 1:
			selectionSort(lista, size, &stats);
		break;
		case 2:
			bubbleSort(lista, size, &stats);
		break;
		case 3:
			quickSort(lista, 0, size - 1, &stats);
		break;
		case 4:
			HeapSort(lista, size, &stats);
		break;
		case 5:
			mergeSort(lista, 0, size - 1, &stats);
		break;
		case 6:
			shellSort(lista, size, &stats);
		break;
		case 7:
			gnomeSort(lista, size, &stats);
		break;
		case 8:
			timsort(lista, size, &stats);
		break;
		case 9:
			countingSort(lista, size, &stats);
		break;
		case 10:
			radixSort(lista, size, &stats);
		break;
		default:
			printf("Opción no valida\n");
		break;
	}

	sumStats(&stats, avgStats);
	printCurrentStats(&stats);
}