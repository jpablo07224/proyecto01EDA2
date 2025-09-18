#include <stdio.h>
#include "ordenamientos.h"
#include "utilerias.h"

void merge(int arr[], int left, int mid, int right, SortStats *stats) {
    // Longitudes de las listas
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[] = new int[n1];
    int R[] = new int[n2];

    // Copiando los valores a las sublistas
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Imprimiendo L y R en cada iteración
    // printf("Lista L: \n");
    // printArray(L);
    // printf("Lista R: \n");
    // printArray(R);

    int i = 0, j = 0;

    int k = left;
    while (i < n1 && j < n2) {

        //Comparación
        stats->comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // printf("Iteración #: \n" + ++iteracion);
}

void mergeSort(int arr[], int left, int right, SortStats *stats) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right, stats);
    }
}