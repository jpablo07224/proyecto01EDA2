#pragma once

#include <stdio.h>
#include "utilerias.h"

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