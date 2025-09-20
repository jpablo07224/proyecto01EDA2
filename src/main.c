#include <stdio.h>

#include <stdlib.h> // malloc
#include <stdbool.h>
#include <time.h>

#include "algoritmos.h"
#include "utilerias.h"
#include "stats.h"

int main (){
    srand(time(NULL));

    //Longitudes de los arreglos
    int lengths[] = {50, 100, 500, 800, 1000, 2000, 5000, 10000};
    char algorithms[][20] = {"InsertionSort", "SelectionSort", "BubbleSort", "QuickSort", "HeapSort", "MergeSort", "ShellSort", "GnomeSort", "TimSort", "CountingSort", "RadixSort"};

    //opciones para el menú
    int algoritmo, longitud;

    //Arreglo dinámico
    int *arregloNumeros;
    //Promedio de los datos
    SortStats averageStats = getNewStats(lengths[longitud]);

    //Archivo para exportar los datos
    FILE *archivoResultados = fopen("resultados.csv", "w");

    //Verificando
    if (archivoResultados == NULL) {
        printf("Error al abrir el archivo de resultados.\n");
        // return 1;
    }

    //Cabecera del CSV
    fprintf(archivoResultados, "Algoritmo,Tamaño,Comparaciones,Intercambios,Inserciones\n");

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

        printf("11: Exit (abortar)\n");
        
        scanf("%d", &algoritmo);

        // Abortar ejecución (opción Exit)
        if (algoritmo == MENU_EXIT)
            break;

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
        printf("\nAlgoritmo: %s\n", algorithms[algoritmo]);
        printf("Long. del arreglo: %i\n", lengths[longitud]);
        
        printf("-----------------------------------\n");

        int size = lengths[longitud];
        SortStats currentStats = getNewStats(size);

        for (int i = 0; i < 5; i++) {
            //Arreglo dinámico
            arregloNumeros = createRandomArray(size);
            //Llamada al algoritmo correspondiente
            switch (algoritmo) {
                case 0:
                insertionSort(arregloNumeros, size, &currentStats);
                sumStats(&currentStats, &averageStats);
                printCurrentStats(&currentStats);
                break;
                case 1:
                selectionSort(arregloNumeros, size, &currentStats);
                sumStats(&currentStats, &averageStats);
                printCurrentStats(&currentStats);
                break;
                case 2:
                bubbleSort(arregloNumeros, size, &currentStats);
                sumStats(&currentStats, &averageStats);
                printCurrentStats(&currentStats);
                break;
                case 3:
                quickSort(arregloNumeros, 0, size - 1, &currentStats);
                sumStats(&currentStats, &averageStats);
                printCurrentStats(&currentStats);
                break;
                case 4:
                HeapSort(arregloNumeros, size, &currentStats);
                sumStats(&currentStats, &averageStats);
                printCurrentStats(&currentStats);
                break;
                case 5:
                mergeSort(arregloNumeros, 0, size - 1, &currentStats);
                sumStats(&currentStats, &averageStats);
                printCurrentStats(&currentStats);
                break;
                case 6:
                shellSort(arregloNumeros, size, &currentStats);
                sumStats(&currentStats, &averageStats);
                printCurrentStats(&currentStats);
                break;
                case 7:
                gnomeSort(arregloNumeros, size, &currentStats);
                sumStats(&currentStats, &averageStats);
                printCurrentStats(&currentStats);
                break;
                case 8:
                timsort(arregloNumeros, size, &currentStats);
                sumStats(&currentStats, &averageStats);
                printCurrentStats(&currentStats);
                break;
                case 9:
                countingSort(arregloNumeros, size, &currentStats);
                sumStats(&currentStats, &averageStats);
                printCurrentStats(&currentStats);
                break;
                case 10:
                radixSort(arregloNumeros, size, &currentStats);
                sumStats(&currentStats, &averageStats);
                printCurrentStats(&currentStats);
                break;
                default:

                break;
            }

        }

        //Obtener promedio
        printf("\n\t\t| Tabla de promedios |\n\n");
        getAverageStats(&averageStats);
        printResultsTable(algorithms[algoritmo], size, &averageStats);

        //Escribir los datos Promedio en el archivo resultados
        fprintf(archivoResultados, "%s,%i,%lli,%lli,%lli\n", 
                algorithms[algoritmo],
                size,
                averageStats.comparisons,
                averageStats.swaps,
                averageStats.insertions);

        //Evitar que se repita el ciclo inmediatamente
        printf("\nPresiona ENTER para continuar...\n\n");
        char buffer;
        scanf("%c", &buffer);
        getchar();

        //reinicializar en 0
        initStats(&averageStats);
    }

    free(arregloNumeros);

    return 0;
}