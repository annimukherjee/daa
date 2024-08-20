#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000 // Maximum size of array

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[low], &arr[i - 1]);
    return (i - 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

double measureTime(int arr[], int n)
{
    clock_t start, end;
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main()
{
    srand(time(NULL));
    int sizes[] = {10, 100, 1000, 5000, 10000, 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    int bestCase[MAX_SIZE], worstCase[MAX_SIZE], avgCase[MAX_SIZE];

    printf("Input Size,Best Case Time,Worst Case Time,Average Case Time\n");

    for (int i = 0; i < num_sizes; i++)
    {
        int n = sizes[i];

        // Generate best case (already sorted)
        for (int j = 0; j < n; j++)
        {
            bestCase[j] = j;
        }

        // Generate worst case (reverse sorted)
        for (int j = 0; j < n; j++)
        {
            worstCase[j] = n - j - 1;
        }

        // Generate average case (random numbers)
        for (int j = 0; j < n; j++)
        {
            avgCase[j] = rand() % 100;
        }

        double bestTime = measureTime(bestCase, n);
        double worstTime = measureTime(worstCase, n);
        double avgTime = measureTime(avgCase, n);

        printf("%d,%.6f,%.6f,%.6f\n", n, bestTime, worstTime, avgTime);
    }

    return 0;
}