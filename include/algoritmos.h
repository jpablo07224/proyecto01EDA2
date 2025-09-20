#include "stats.h"

#pragma once

// Estructura para la lista de cada cubeta
typedef struct Node{
    int data;
    struct Node* next;
} Node;

#define RUN 32

void bubbleSort(int a[], int size, SortStats *stats);

void gnomeSort(int arr[], int n, SortStats *stats);

void HeapSort(int* A, int size, SortStats *stats);
int BuildHeap(int* A, int size, SortStats *stats);
void Heapify(int* A, int i, int size, int heapSize, SortStats *stats);

void insertionSort(int a[], int n, SortStats *stats);

void merge(int arr[], int left, int mid, int right, SortStats *stats);
void mergeSort(int arr[], int left, int right, SortStats *stats);

void quickSort(int arr[], int low, int high, SortStats *stats);
int partition (int arr[], int low, int high, SortStats *stats);

void selectionSort(int arreglo[], int n, SortStats *stats);

void shellSort(int arr[], int n, SortStats *stats);

void insertionSortTim(int arr[], int left, int right, SortStats *stats);
void mergeTim(int arr[], int l, int m, int r, SortStats *stats);
void timsort(int arr[], int n, SortStats *stats);

void countingSort(int arr[], int n, SortStats *stats);

void radixSort(int arr[], int n, SortStats *stats);
void distributeAndCollect(int arr[], int n, int exp, SortStats *stats);