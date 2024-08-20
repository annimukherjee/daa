#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1)
    {
        while (i <= j && arr[i] <= pivot)
            i++;
        while (i <= j && arr[j] > pivot)
            j--;
        if (i > j)
            break;
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
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

int main()
{
    int arr[ARRAY_SIZE];
    clock_t start, end;
    double time_taken;

    printf("The array size is: %d\n", ARRAY_SIZE);
    srand(time(NULL)); 

    // Best Case
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = i;
    }
    start = clock();
    quickSort(arr, 0, ARRAY_SIZE - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("(Already Sorted) Time: %f seconds\n", time_taken);

    // Average Case
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % ARRAY_SIZE;
    }
    start = clock();
    quickSort(arr, 0, ARRAY_SIZE - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("(Random Numbers) Time: %f seconds\n", time_taken);

    // Worst Case
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = ARRAY_SIZE - i - 1;
    }
    start = clock();
    quickSort(arr, 0, ARRAY_SIZE - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("(Descending Order) Time: %f seconds\n", time_taken);

    return 0;
}