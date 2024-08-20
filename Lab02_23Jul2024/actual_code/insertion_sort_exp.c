#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long totalMoves = 0;
long long totalOperations = 0;

void insertionSort(int arr[], int n) {
    totalOperations++;
    int i, key, j;
    totalOperations++;
    for (i = 1; i < n; i++) {
        totalOperations++;
        key = arr[i];
        totalOperations++;
        j = i - 1;
        totalOperations++;
        while (j >= 0 && arr[j] > key) {
            totalOperations++;
            arr[j + 1] = arr[j];
            totalOperations++;
            j = j - 1;
            totalOperations++;
            totalMoves++;
        }
        arr[j + 1] = key;
        totalOperations++;
    }
}

void generateArray(int arr[], int n, int case_type) {
    for (int i = 0; i < n; i++) {
        if (case_type == 0) // Best case (already sorted)
            arr[i] = i;
        else if (case_type == 1) // Worst case (reverse sorted)
            arr[i] = n - i - 1;
        else // Average case (random)
            arr[i] = rand() % n;
    }
}

int main() {
    srand(time(NULL));
    printf("Size,Best Case Time,Best Case Moves,Best Case Operations,Avg Case Time,Avg Case Moves,Avg Case Operations,Worst Case Time,Worst Case Moves,Worst Case Operations\n");

    for (int n = 10; n <= 50000; n = 
        (n < 100) ? n + 1 : 
        (n < 1000) ? n + 50 : 
        (n < 5000) ? n + 100 : 
        (n < 15000) ? n + 500 : 
        (n < 30000) ? n + 5000 : n + 7500) {
        
        int *arr = (int *)malloc(n * sizeof(int));
        clock_t start, end;
        double cpu_time_used;

        // Best Case
        generateArray(arr, n, 0);
        totalMoves = totalOperations = 0;
        start = clock();
        insertionSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%d,%.6f,%lld,%lld,", n, cpu_time_used, totalMoves, totalOperations);

        // Average Case
        generateArray(arr, n, 2);
        totalMoves = totalOperations = 0;
        start = clock();
        insertionSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%.6f,%lld,%lld,", cpu_time_used, totalMoves, totalOperations);

        // Worst Case
        generateArray(arr, n, 1);
        totalMoves = totalOperations = 0;
        start = clock();
        insertionSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%.6f,%lld,%lld\n", cpu_time_used, totalMoves, totalOperations);

        free(arr);
    }

    return 0;
}