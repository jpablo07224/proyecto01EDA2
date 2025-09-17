#include <stdio.h>
#include "ordenamientos.h"
#include "utilerias.h"

//QuickSort
void quickSort(int arr[], int low, int high){
    if (low < high){
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
    }
}

int partition (int arr[], int low, int high){
	int pivot = arr[high];
	int j,i = (low - 1);  
	for (j = low; j <= high- 1; j++){
		if (arr[j] <= pivot){
			i++;    
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}