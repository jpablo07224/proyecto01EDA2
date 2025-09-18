#include <stdio.h>
#include "quickSort.h"
#include "utilerias.h"

void quickSort(int arr[], int low, int high, SortStats *stats){
    if (low < high){
		int pi = partition(arr, low, high, stats);
		quickSort(arr, low, pi - 1, stats);
		quickSort(arr, pi + 1, high, stats);
    }
}

int partition (int arr[], int low, int high, SortStats *stats){
	int pivot = arr[high];
	int j,i = (low - 1);
	for (j = low; j <= high- 1; j++){
		//Comparación
		stats->comparisons++;
		if (arr[j] <= pivot){
			i++;
			//Intercambio
			stats->swaps++;
			swap(&arr[i], &arr[j]);
		}
	}
	//Intercambio
	stats->swaps++;
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}