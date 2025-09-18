#include <stdio.h>
#include <stdlib.h> // Para min() si se usa

#include "utilerias.h"
#include "timSort.h"

#define RUN 32

// Función de inserción para ordenar las "runs" de Timsort
void insertionSortTim(int arr[], int left, int right, SortStats *stats) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > temp) {
            //Comparación
            stats->comparisons++;
            arr[j + 1] = arr[j];
            //Intercambio
            stats->swaps++;
            j--;
        }
        //Comparación
        stats->comparisons++; // La comparación que falla
        arr[j + 1] = temp;
    }
}

// Función de mezcla para Timsort
void mergeTim(int arr[], int l, int m, int r, SortStats *stats) {
    int len1 = m - l + 1;
    int len2 = r - m;
    int left[len1], right[len2];

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < len1 && j < len2) {
        //Comparación
        stats->comparisons++;

        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Función principal de Timsort
void timsort(int arr[], int n, SortStats *stats) {
    // 1. Ordenar sub-arreglos individuales de tamaño RUN
    for (int i = 0; i < n; i += RUN) {
        int right_boundary = (i + RUN - 1 < n - 1) ? (i + RUN - 1) : (n - 1);
        insertionSortTim(arr, i, right_boundary, stats);
    }

    // 2. Empezar a mezclar desde el tamaño RUN. Se duplica en cada iteración.
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? (left + 2 * size - 1) : (n - 1);

            if (mid < right) {
                mergeTim(arr, left, mid, right, stats);
            }
        }
    }
}