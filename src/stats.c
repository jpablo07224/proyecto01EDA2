/*
-       Autor: Muñoz Peña Juan Pablo
-       Editores: Prado Garcia Juan David, Correa Sam Said
-
-       Fecha de última modificación: Martes 23 de Septiembre
-
-       Proposito: Contiene las funciones usadas para el cálculo de las comparaciones.
-
-*/

#include <stdio.h>
#include "stats.h"

SortStats getNewStats(int size) {
	SortStats stats;

	//inicializar valores
    initStats(&stats);
	stats.dataSize = size;

	return stats;
}

//Inicializar en ceros
void initStats(SortStats *stats) {
	stats->comparisons = 0;
	stats->swaps = 0;
	stats->insertions = 0;
	stats->bytes = 0;
}

void sumStats(SortStats *stats, SortStats *averageStats) {
	averageStats->comparisons += stats->comparisons;
	averageStats->swaps += stats->swaps;
	averageStats->insertions += stats->insertions;
	averageStats->bytes += stats->bytes;
}

void getAverageStats(SortStats *averageStats) {
	averageStats->comparisons /=  ALG_NUM_EXECUTIONS;
	averageStats->swaps /= ALG_NUM_EXECUTIONS;
	averageStats->insertions /= ALG_NUM_EXECUTIONS;
	averageStats->bytes /= ALG_NUM_EXECUTIONS;
}

void printCurrentStats(SortStats *stats) {
	printf("Comparaciones: %lli |\t", stats->comparisons);
	printf("Intercambios: %lli |\t", stats->swaps);
	printf("Inserciones: %lli |\t\n", stats->insertions);
	printf("Bytes: %lli |\t\n", stats->bytes);
}

void printResultsTable(const char *algorithm, int size, SortStats *stats) {
    // printf("Algoritmo: %s \n", algorithm);
    // printf("número de datos: %i \n", size);

    printCurrentStats(stats);
}