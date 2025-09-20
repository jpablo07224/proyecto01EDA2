#pragma once

#define MENU_ALG_INSERTIONSORT 0
#define MENU_ALG_SELECTIONSORT 1
#define MENU_ALG_BUBBLESORT 2
#define MENU_ALG_QUICKSORT 3
#define MENU_ALG_HEAPSORT 4
#define MENU_ALG_MERGESORT 5
#define MENU_ALG_SHELLSORT 6
#define MENU_ALG_GNOMESORT 7
#define MENU_ALG_TIMSORT 8
#define MENU_ALG_COUNTINGSORT 9
#define MENU_ALG_RADIXSORT 10

#define MENU_EXIT 11

#define MENU_ARRAY_50 0
#define MENU_ARRAY_100 1
#define MENU_ARRAY_500 2
#define MENU_ARRAY_1000 3
#define MENU_ARRAY_2000 4
#define MENU_ARRAY_5000 5
#define MENU_ARRAY_10000 6

#define ALG_MAX_RANGE 400

void swap(int *a, int *b);
void printArray(int a[], int n);
void printSubArray(int arr[],int low, int high);

int* createRandomArray(int size);
