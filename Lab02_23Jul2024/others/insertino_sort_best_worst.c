#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generateArray(int size, int option)
{
    int *arr = (int *)malloc(size * sizeof(int));
    srand(time(0));
    if (option == 0)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = i;
        }
    }
    else if (option == 1)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            arr[size - i - 1] = i;
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 101;
        }
    }
    return arr;
}

void insertionSort(int *arr, int size, long int *step, long int *count)
{
    for (int j = 1; j < size; j++)
    {
        (*step)++;
        int i = j - 1;
        (*step)++;
        int key = arr[j];
        (*step)++;
        while (i >= 0 && arr[i] > key)
        {
            (*step)++;
            arr[i + 1] = arr[i];
            (*step)++;
            i--;
            (*step)++;
            (*count)++;
        }
        (*step)++;
        arr[i + 1] = key;
        (*step)++;
    }
}

int main()
{
    int size = 10000;
    int *arr = generateArray(size, 1);

    long int step = 0, count = 0;
    insertionSort(arr, size, &step, &count);

    printf("Steps: %ld\n", step);
    printf("Count: %ld\n", count);

    free(arr);
    return 0;
}