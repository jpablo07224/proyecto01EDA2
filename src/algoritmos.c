/*
-       Autor: Prado Garcia Juan David, Correa Sam Said, Muñoz Peña Juan Pablo
-
-       Fecha de última modificación: Martes 23 de Septiembre
-
-       Proposito: Archivo que contiene todos los algoritmos de ordenamiento usados en el programa.
-
-*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilerias.h"
#include "stats.h"
#include "algoritmos.h"

// -- BubbleSort con mejora --
void bubbleSort(int a[], int size, SortStats *stats) {

    for (int i = size - 1; i > 0; i--) {
        int sinCambios = 1;

        for (int j = 0; j < i; j++) {
            stats->comparisons++;

            if (a[j] > a[j+1]){
                stats->swaps++;
				swap(&a[j], &a[j+1]);
				sinCambios = 0;
            }
        }

		if (sinCambios)
            break;
    }
}

// -- GnomeSort --
void gnomeSort(int arr[], int n, SortStats *stats) {
    int pos = 0;
    while (pos < n) {
        if (pos == 0) {
            pos++;
            continue;
        }

        stats->comparisons++;   //Comparación

        if (arr[pos] >= arr[pos - 1]) {
            pos++;  // Si está en orden, avanza
        } else {
            // Si no, intercambia y retrocede
            swap(&arr[pos - 1], &arr[pos]);
            pos--;

            stats->swaps++; //Intercambio
        }
    }
}

// -- HeapSort --
void HeapSort(int* A, int size, SortStats *stats){
	int heapSize = BuildHeap(A,size, stats);

	for(int i = size - 1; i > 0; i--){
		stats->swaps++; //Intercambio
		swap(&A[0],&A[heapSize]);
		heapSize--;
		Heapify(A, 0,size, heapSize, stats);
	}
}

int BuildHeap(int* A, int size, SortStats *stats){
	int heapSize = size - 1;

	for(int i = (size - 1) / 2; i >= 0; i--){
		Heapify(A, i,size, heapSize, stats);
	}

	return heapSize;
}

void Heapify(int* A, int i, int size, int heapSize, SortStats *stats) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;

	stats->comparisons++;
    if (l <= heapSize) {
        stats->comparisons++;
        if(A[l] > A[i])
            largest = l;
    }
    
	stats->comparisons++;
	if(r <= heapSize) {
        stats->comparisons++;
        if (A[r] > A[largest]) 
            largest = r;
    }
	
	stats->comparisons++;
	if(largest != i){
		stats->swaps++;
		swap(&A[i],&A[largest]);
		Heapify(A, largest,size, heapSize, stats);
	}
}

// -- InsertionSort --
void insertionSort(int a[], int n, SortStats *stats){
	int i,j;
	int aux;

	for(i=1; i<n; i++){
		j=i;
		aux=a[i];
		
        stats->comparisons++; //Comparación

		while (j>0 && aux < a[j-1]){
			stats->insertions++;
			a[j] = a[j - 1];
			j--;

            if (j > 0) stats->comparisons++;
		}

		a[j]=aux;
        stats->insertions++;
	}
}

// -- MergeSort --
void merge(int arr[], int left, int mid, int right, SortStats *stats) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1];
    int R[n2];
    
    // MODIFICACIÓN: Suma los bytes de los arreglos temporales L y R
    stats->bytes += (n1 + n2);

    // El resto de la función permanece igual...
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
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
}

// La función mergeSort principal no necesita cambios
void mergeSort(int arr[], int left, int right, SortStats *stats) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, stats);
        mergeSort(arr, mid + 1, right, stats);
        merge(arr, left, mid, right, stats);
    }
}

// -- QuickSort --
void quickSort(int arr[], int low, int high, SortStats *stats){
    if (low < high){
		int pi = partition(arr, low, high, stats);
		quickSort(arr, low, pi - 1, stats);
		quickSort(arr, pi + 1, high, stats);
    }
}

int partition (int arr[], int low, int high, SortStats *stats){
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		stats->comparisons++; //Comparación
		if (arr[j] <= pivot) {
			i++;
			stats->swaps++; //Intercambio
			swap(&arr[i], &arr[j]);
		}
	}

	stats->swaps++; //Intercambio
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

// -- SelectionSort --
void selectionSort(int arreglo[], int n, SortStats *stats){
	for (int i = 0; i < n - 1; i++){
		int indiceMenor = i;
		for (int j = i + 1; j < n; j++){
			stats->comparisons++; //Comparación
			if (arreglo[j] < arreglo[indiceMenor])
				indiceMenor = j;
		}

		if (i != indiceMenor){
			stats->swaps++; //Intercambio
			swap(&arreglo[i],&arreglo[indiceMenor]);
		}
	}
}

// -- ShellSort --
void shellSort(int arr[], int n , SortStats *stats) {
    // Calcula el gap inicial usando la secuencia de Knuth
    int gap = 1;

    while (gap < n / 3) {
        gap = 3 * gap + 1;
    }

    // Comienza a ordenar con el gap más grande y lo reduce
    for (; gap > 0; gap /= 3) {
        // Realiza un ordenamiento por inserción para este gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            
            // Desplaza los elementos anteriores del gap que son mayores
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                stats->comparisons++; //Comparación
                arr[j] = arr[j - gap];
                stats->swaps++; //Intercambio
            }

            stats->comparisons++; // La comparación final que falla

            arr[j] = temp;
        }
    }
}

// -- TimSort --

// Función de inserción para ordenar las "runs" de Timsort
void insertionSortTim(int arr[], int left, int right, SortStats *stats) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > temp) {
            stats->comparisons++; //Comparación
            arr[j + 1] = arr[j];
            stats->swaps++; //Intercambio
            j--;
        }

        stats->comparisons++; // La comparación que falla
        arr[j + 1] = temp;
    }
}

// Función de mezcla para Timsort
void mergeTim(int arr[], int l, int m, int r, SortStats *stats) {
    int len1 = m - l + 1;
    int len2 = r - m;
    int left[len1], right[len2];

    // MODIFICACIÓN: Suma los bytes de los arreglos temporales
    stats->bytes += (len1 + len2);

    // El resto de la función permanece igual...
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < len1 && j < len2) {
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


// -- CountingSort --

void countingSort(int arr[], int n, SortStats *stats) {
    if (n <= 1) return;

    int max = getMax(arr, n);
    
    // Crea el arreglo de conteo y el arreglo de salida
    int *count = (int *)malloc((max + 1) * sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    // MODIFICACIÓN: Suma los bytes de AMBOS arreglos creados
    stats->bytes += (max + 1);
    stats->bytes += n;
    
    // El resto de la función permanece igual...
    memset(count, 0, (max + 1) * sizeof(int));

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

// -- RadixSort --
void radixSort(int arr[], int n, SortStats *stats) {
    if (n <= 1) return;

    // Encuentra el número máximo
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        distributeAndCollect(arr, n, exp, stats);
    }
}


void distributeAndCollect(int arr[], int n, int exp, SortStats *stats) {
    Node* buckets[10] = {NULL};

    // MODIFICACIÓN: Suma los bytes de todos los nodos que se crearán
    // (un nodo por cada elemento del arreglo)
    stats->bytes += n;
    
    // 1. Distribuye los números del arreglo en las cubetas
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;

        // Crea un nuevo nodo
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        
        // Agrega el nodo a la cubeta correspondiente
        if (buckets[digit] == NULL) {
            buckets[digit] = newNode;
        } else {
            Node *temp = buckets[digit];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // 2. Recolecta los números de las cubetas de vuelta al arreglo
    int index = 0;
    for (int i = 0; i < 10; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            Node *toFree = current;
            current = current->next;
            free(toFree);// Libera la memoria del nodo
        }
    }
}