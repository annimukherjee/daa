#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long steps;

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        steps++; // Counting comparison
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        steps++; // Counting assignment
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        steps++; // Counting assignment
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        steps++; // Counting assignment
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void runTest(int size)
{
    int *asc = malloc(size * sizeof(int));
    int *desc = malloc(size * sizeof(int));
    int *rand_arr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        asc[i] = i;
        desc[i] = size - i - 1;
        rand_arr[i] = rand() % 100;
    }

    clock_t start, end;
    double time_best, time_worst, time_avg;
    long long steps_best, steps_worst, steps_avg;

    steps = 0;
    start = clock();
    mergeSort(asc, 0, size - 1);
    end = clock();
    time_best = (double)(end - start) / CLOCKS_PER_SEC;
    steps_best = steps;

    steps = 0;
    start = clock();
    mergeSort(desc, 0, size - 1);
    end = clock();
    time_worst = (double)(end - start) / CLOCKS_PER_SEC;
    steps_worst = steps;

    steps = 0;
    start = clock();
    mergeSort(rand_arr, 0, size - 1);
    end = clock();
    time_avg = (double)(end - start) / CLOCKS_PER_SEC;
    steps_avg = steps;

    printf("%d,%.6f,%lld,%.6f,%lld,%.6f,%lld\n",
           size, time_best, steps_best, time_worst, steps_worst, time_avg, steps_avg);

    free(asc);
    free(desc);
    free(rand_arr);
}

int main()
{
    int sizes[] = {10, 100, 500, 1000, 4000, 8000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));

    printf("Size,Best Case Time,Best Case Steps,Worst Case Time,Worst Case Steps,Average Case Time,Average Case Steps\n");

    // Run tests for the original range
    for (int i = 0; i < num_sizes; i++)
    {
        runTest(sizes[i]);
    }

    // Run tests for the new range (50,000 to 100,000 in steps of 5,000)
    for (int size = 55000; size <= 100000; size += 5000)
    {
        runTest(size);
    }

    return 0;
}