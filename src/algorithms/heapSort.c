#include <stdio.h>
#include "heapSort.h"
#include "utilerias.h"

void HeapSort(int* A, int size, SortStats *stats){
	int heapSize = BuildHeap(A,size, stats);
	int i;
	for(i = size - 1; i > 0; i--){
		//Intercambio
		stats->swaps++;
		swap(&A[0],&A[heapSize]);
		heapSize--;
		Heapify(A, 0,size, heapSize, stats);
	}
}

int BuildHeap(int* A, int size, SortStats *stats){
	int heapSize = size - 1;
	int i;
	for(i = (size - 1) / 2; i >= 0; i--){
		Heapify(A, i,size, heapSize, stats);
	}

	return heapSize;
}

void Heapify(int* A, int i, int size, int heapSize, SortStats *stats) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest;

	//Comparaciones x2
	stats->comparisons += 2;
	if(l <= heapSize && A[l] > A[i])
	largest = l;
	else
	largest = i;
	//Comparaciones x2
	stats->comparisons += 2;
	if(r <= heapSize && A[r] > A[largest])
	largest = r;
	//Comparación
	stats->comparisons++;
	if(largest != i){
		//Intercambio
		stats->swaps++;
		swap(&A[i],&A[largest]);
		Heapify(A, largest,size, heapSize, stats);
	}
}