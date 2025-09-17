#include <stdio.h>
#include "ordenamientos.h"
#include "utilerias.h"

//HeapSort
void HeapSort(int* A, int size){
	int heapSize = BuildHeap(A,size);
	int i;
	for(i = size - 1; i > 0; i--){
		swap(&A[0],&A[heapSize]);
		heapSize--;
		Heapify(A, 0,size, heapSize);
	}
}

int BuildHeap(int* A, int size){
	int heapSize = size - 1;
	int i;
	for(i = (size - 1) / 2; i >= 0; i--){
		Heapify(A, i,size, heapSize);
	}

	return heapSize;
}

void Heapify(int* A, int i, int size, int heapSize) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest;

	if(l <= heapSize && A[l] > A[i])
		largest = l;
	else
		largest = i;
	if(r <= heapSize && A[r] > A[largest])
		largest = r;
	if(largest != i){
		swap(&A[i],&A[largest]);
		Heapify(A, largest,size, heapSize);
	}
}