//Encapsular los datos
typedef struct {
	//Prevenir overflow
    long long comparisons;
    long long swaps;
    long long insertions;

	long long dataSize;
} SortStats;

SortStats initializeSortStats(int size) {
	SortStats stats;
    initStats(&stats);
	SortStats.dataSize = size;
	return stats;
}

void initStats(SortStats *stats) {

}

void printResultsTable(const char* algorithm, int size, const){
    
}