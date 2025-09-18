#pragma once

void HeapSort(int* A, int size, SortStats *stats);
int BuildHeap(int* A, int size, SortStats *stats);
void Heapify(int* A, int i, int size, int heapSize, SortStats *stats);