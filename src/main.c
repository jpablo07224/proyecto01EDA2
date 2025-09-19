#include <stdio.h>

#include <stdlib.h> // malloc
#include <stdbool.h>
#include <time.h>

#include "algoritmos.h"
#include "utilerias.h"

int main (){
    srand(time(NULL));

    //Longitudes de los arreglos
    int lengths[] = {50, 100, 500, 800, 1000, 2000, 5000, 10000};
    char algorithms[][] = {"InsertionSort", "SelectionSort", "BubbleSort", "QuickSort", "HeapSort", "MergeSort", "ShellSort", "GnomeSort", "TimSort", "CountingSort", "RadixSort"};

    //opciones para el menú
    int algoritmo, longitud;

    //Arreglo dinámico
    int *listaNumeros;

    while (true) {

    /* Algoritmos */
        printf("\nSeleccionar algoritmo: \n");

        printf("0: InsertionSort\n");
        printf("1: SelectionSort\n");
        printf("2: BubbleSort\n");

        printf("3: QuickSort\n");
        printf("4: HeapSort\n");
        printf("5: MergeSort\n");

        printf("6: ShellSort\n");
        printf("7: GnomeSort\n");
        printf("8: TimSort\n");

        printf("9: CountingSort\n");
        printf("10: RadixSort\n");

        // printf("11: Exit (abortar)\n");
        
        scanf("%d", &algoritmo);

        // // Abortar ejecución (opción Exit)
        // if (algoritmo == MENU_EXIT)
        //     break;

    /* Cantidad de datos por arreglo */
        printf("Número de valores por arreglo: \n");

        printf("0: 50\n");
        printf("1: 100\n");
        printf("2: 500\n");

        printf("3: 1,000\n");
        printf("4: 2,000\n");
        printf("5: 5,000\n");

        printf("6: 10,000\n");

        scanf("%d", &longitud);

        //Datos seleccionados
        printf("Algoritmo: \n", algorithms[algoritmo]);
        printf("Long. del arreglo: \n", lengths[longitud]);

        //Arreglo dinámico
        int n;
        printf("Longitud:");
        scanf("%i", &n);
        listaNumeros = (int *) malloc(lengths[n] * sizeof(int));

        //Verificar asignación de memoria
        if (listaNumeros == NULL)
            return 1;

        //Creación
        for (int i = 0; i < lengths[n]; i++) {
            listaNumeros[i] = rand() % (ALG_MAX_RANGE + 1);
        }

        //Llamada al algoritmo correspondiente
        if (opcion == ALG_INSERTION_OPT)
            insertionSort(copiaListaNumeros, ALG_ARRAY_LENGTH);
        else if (opcion == ALG_SELECTION_OPT)
            selectionSort(copiaListaNumeros, ALG_ARRAY_LENGTH);
        else if (opcion == ALG_BUBBLE_OPT)
            bubbleSort(copiaListaNumeros, ALG_ARRAY_LENGTH);
        else if (opcion == ALG_QUICK_OPT)
            quickSort(copiaListaNumeros, 0, ALG_ARRAY_LENGTH - 1);
        else if (opcion == ALG_HEAP_OPT)
            HeapSort(copiaListaNumeros, ALG_ARRAY_LENGTH);

        //Evitar que se repita el ciclo inmediatamente
        printf("\nPresiona ENTER para continuar...\n\n");
        char buffer;
        scanf("%c", &buffer);
        getchar();
    }

    free(listaNumeros);

    return 0;
}