#pragma once

#define ALG_NUM_EXECUTIONS 5

//Encapsular los datos
typedef struct {
	//Prevenir overflow
    long long comparisons;
    long long swaps;
    long long insertions;
    long long bytes;

	long long dataSize;
} SortStats;

SortStats getNewStats(int size);
void initStats(SortStats *stats);
void sumStats(SortStats *stats, SortStats *averageStats);
void getAverageStats(SortStats *averageStats);
void printCurrentStats(SortStats *stats);
void printResultsTable(const char *algorithm, int size, SortStats *stats);