#include <stdio.h>
#include "ordenamientos.h"
#include "utilerias.h"

//BubbleSort con mejora (abortar si ya está ordenado)
void bubbleSort(int a[], int size) {
	int i, j, n;
	n = size;
    for (i = n-1; i > 0; i--) {
        int sinCambios = 1;//bandera
        for (j = 0; j < i; j++) {
            if (a[j] > a[j+1]){
                printf("Intercambiando %i [%i] por %i [%i]\n", a[j], j, a[j+1], j+1);
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