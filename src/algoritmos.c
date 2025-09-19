#include <stdio.h>
#include <stdlib.h> //<---

#include "utilerias.h"


// -- BubbleSort con mejora --
void bubbleSort(int a[], int size, SortStats *stats) {
	int i, j, n;
	n = size;
    for (i = n-1; i > 0; i--) {
        int sinCambios = 1;//bandera
        for (j = 0; j < i; j++) {
            //Comparaciones
            stats->comparisons++;
            if (a[j] > a[j+1]){
                printf("Intercambiando %i [%i] por %i [%i]\n", a[j], j, a[j+1], j+1);
                stats->swaps++;
				swap(&a[j], &a[j+1]);
				sinCambios = 0;
            }
        }
		if (sinCambios) {//Parar si ya no hay cambios
			printf("Deteniendo ejecución de bubbleSort en la vuelta #%i...", size - i);
            break;
        }
    }
}

// -- GnomeSort --
void gnomeSort(int arr[], int n, SortStats *stats) {
    int pos = 0;
    while (pos < n) {
        // La primera parte de la condición no es una comparación de elementos
        if (pos == 0) {
            pos++;
            continue;
        }
        
        // Aquí se realiza la comparación clave
        //Comparación
        stats->comparisons++;

        if (arr[pos] >= arr[pos - 1]) {
            // Si está en orden, avanza
            pos++;
        } else {
            // Si no, intercambia y retrocede
            //Cambiar por swap
            int temp = arr[pos];
            arr[pos] = arr[pos - 1];
            arr[pos - 1] = temp;

            //Intercambio
            stats->swaps++;

            pos--;
        }
    }
}

// -- HeapSort --
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

// -- InsertionSort --
void insertionSort(int a[], int n, SortStats *stats){
	int i,j,k; // Indices
	int aux; // Copia del valor

	for(i=1; i<n; i++){
		j=i;
		aux=a[i];
		//Comparación
		while (j>0 && aux < a[j-1]){
			stats->comparisons++;
            printf("Intercambiando %i [%i] por %i [%i]\n", a[j], j, a[j-1], j-1);
			//Intercambio
			stats->swaps++;
			a[j] = a[j-1];
			j--;
		}
		a[j]=aux;

	}
}

// -- MergeSort --
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
}

void mergeSort(int arr[], int left, int right, SortStats *stats) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

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
	int j,i = (low - 1);
	for (j = low; j <= high- 1; j++){
		//Comparación
		stats->comparisons++;
		if (arr[j] <= pivot){
			i++;
			//Intercambio
			stats->swaps++;
			swap(&arr[i], &arr[j]);
		}
	}
	//Intercambio
	stats->swaps++;
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

// -- SelectionSort --
void selectionSort(int arreglo[], int n, SortStats *stats){
	int indiceMenor, i, j; // indices

	for (i = 0; i < n - 1; i++){
		indiceMenor = i;
		for (j = i + 1; j < n; j++){
			//Comparación
			stats->comparisons++;
			if (arreglo[j] < arreglo[indiceMenor])
				indiceMenor = j;
		}
		if (i != indiceMenor){
			//Intercambio
			stats->swaps++;
            printf("Intercambiando %i [%i] por %i [%i]\n", arreglo[i], i, arreglo[indiceMenor], indiceMenor);
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
            // Aquí contarías una comparación por cada vuelta del bucle
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                //Comparación
                stats->comparisons++;
                arr[j] = arr[j - gap];
                //Intercambio
                stats->swaps++;
            }
            //Comparación
            stats->comparisons++; // La comparación final que falla
            
            arr[j] = temp;
        }
    }
}

// -- TimSort --
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


// -- CountingSort --



// -- RadixSort --
