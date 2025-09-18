#include <stdio.h>
#include "utilerias.h"

//Encapsular los datos
typedef struct {
	//Prevenir overflow
    long long comparisons;
    long long swaps;
    long long insertions;

	long long dataSize;
} SortStats;

SortStats initializeSortStats(int size) {
	SortStats stats;
	SortStats.dataSize = size;
	return stats;
}

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