#include <stdio.h>
#include "stats.h"

SortStats getNewStats(int size) {
	SortStats stats;
    initStats(&stats);
	stats.dataSize = size;
	return stats;
}

void initStats(SortStats *stats) {
	stats->comparisons = 0;
	stats->swaps = 0;
	stats->insertions = 0;
}

void sumStats(SortStats *stats, SortStats *averageStats) {
	averageStats->comparisons += stats->comparisons;
	averageStats->swaps += stats->swaps;
	averageStats->insertions += stats->insertions;
}

void getAverageStats(SortStats *averageStats) {
	averageStats->comparisons /=  5;
	averageStats->swaps /= 5;
	averageStats->insertions /= 5;
}

void printCurrentStats(SortStats *stats) {
	printf("Comparaciones: %lli |\t", stats->comparisons);
	printf("Intercambios: %lli |\t", stats->swaps);
	printf("Inserciones: %lli |\t\n", stats->insertions);
}

void printResultsTable(const char *algorithm, int size, SortStats *stats) {
    // printf("Algoritmo: %s \n", algorithm);
    // printf("número de datos: %i \n", size);

    printCurrentStats(stats);
}