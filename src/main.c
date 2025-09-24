/*
-       Autor: Prado Garcia Juan David, Correa Sam Said
-       Editores: Muñoz Peña Juan Pablo
-
-       Fecha de última modificación: Martes 23 de Septiembre
-
-       Proposito: Función del programa principal (main), aquí es donde se ejecuta el menú y se encarga de exportar los datos.
-
-*/

#include <stdio.h>

#include <stdlib.h> // malloc
#include <stdbool.h>
#include <time.h>
#include <string.h> //strcmp

#include "algoritmos.h"
#include "utilerias.h"
#include "stats.h"

int main (int argc, char*argv[]){
    srand(time(NULL));

    // Algoritmos y Longitudes
    int lengths[] = {50, 100, 500, 800, 1000, 2000, 5000, 10000};
    char algorithms[][20] = {"InsertionSort", "SelectionSort", "BubbleSort", "QuickSort", "HeapSort", "MergeSort", "ShellSort", "GnomeSort", "TimSort", "CountingSort", "RadixSort"};

    // Abrir archivo en modo escritura
    FILE *archivoResultados = fopen("resultados.csv", "w");

    if (archivoResultados == NULL) { //Verificando
        printf("Error al abrir el archivo de resultados.\n");
        // return 1;
    }

    // Escribir la cabecera del CSV
    fprintf(archivoResultados, "Algoritmo,Tamaño,Comparaciones,Intercambios,Inserciones,Bytes\n");

    //Revisar si recibio argumentos al ejecutarse
    if (argc == 2 && strcmp(argv[1], "auto") == 0) {
        // ----- Modo automático ----
        printf("Iniciando ejecución en modo autmático...\n");

        for (int currentAlg = 0; currentAlg < 11; currentAlg++) {
            for (int size = 0; size < 8; size++) {
                SortStats currentStats = getNewStats(lengths[size]);
                SortStats averageStats = getNewStats(lengths[size]);

                printf("Algoritmo: %s\t Tamaño: %i\n", algorithms[currentAlg], lengths[size]);

                for (int k = 0; k < 5; k++) {
                    int *lista = createRandomArray(lengths[size]);
                    ejecutarAlgoritmo(lista, lengths[size], currentAlg, currentStats, &averageStats);
                    free(lista);
                }
                getAverageStats(&averageStats);

                printf("\tPromedios\n");
                printResultsTable(algorithms[currentAlg], lengths[size], &averageStats);
                printf("--------------------------------\n");

                fprintf(archivoResultados, "%s,%i,%lli,%lli,%lli,%lli\n", 
                        algorithms[currentAlg],
                        lengths[size],
                        averageStats.comparisons,
                        averageStats.swaps,
                        averageStats.insertions,
                        averageStats.bytes);
            }
        }

    } else {

        int algoritmo, longitud; //opciones para el menú
        int *arregloNumeros; //Arreglo dinámico
        SortStats averageStats; //Promedio de los datos

        while (true) {
            // Algoritmos 
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

            //Cantidad de datos por arreglo
            printf("Número de valores por arreglo: \n");

            printf("0: 50\n");
            printf("1: 100\n");
            printf("2: 500\n");
            printf("3: 800\n");

            printf("4: 1,000\n");
            printf("5: 2,000\n");
            printf("6: 5,000\n");

            printf("7: 10,000\n");

            scanf("%d", &longitud);

            averageStats = getNewStats(lengths[longitud]);

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
                ejecutarAlgoritmo(arregloNumeros, size, algoritmo, currentStats, &averageStats);
            }

            //Obtener promedio
            printf("\n\t\t| Tabla de promedios |\n\n");
            getAverageStats(&averageStats);
            printResultsTable(algorithms[algoritmo], size, &averageStats);

            //Escribir los datos Promedio en el archivo resultados
            fprintf(archivoResultados, "%s,%i,%lli,%lli,%lli,%lli\n", 
                    algorithms[algoritmo],
                    size,
                    averageStats.comparisons,
                    averageStats.swaps,
                    averageStats.insertions,
                    averageStats.bytes);

            //Evitar que se repita el ciclo inmediatamente
            printf("\nPresiona ENTER para continuar...\n\n");
            char buffer;
            scanf("%c", &buffer);
            getchar();

            initStats(&averageStats); //reinicializar en 0
            free(arregloNumeros); //Liberar memoria
        }
    }
    
    fclose(archivoResultados); //Cerrar archivo

    return 0;
}