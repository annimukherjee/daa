#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int totalMoves = 0;
long int totalOperations = 0;

void insertionSort(int arr[], int arrSize)
{
    totalOperations++;
    int currentElement;
    totalOperations++;
    for (int i = 1; i < arrSize; i++)
    {
        totalOperations++;
        currentElement = arr[i];
        totalOperations++;
        int j = i - 1;
        totalOperations++;
        while (j >= 0 && arr[j] > currentElement)
        {
            totalOperations++;
            arr[j + 1] = arr[j];
            totalOperations++;
            j--;
            totalOperations++;
            totalMoves++;
        }
        arr[j + 1] = currentElement;
        totalOperations++;
    }
}

void print_array(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arrSize;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &arrSize);
    int asc_array[arrSize], desc_array[arrSize], random_array[arrSize];

    for (int i = 0; i < arrSize; i++)
    {
        asc_array[i] = i + 1;
    }
    for (int i = arrSize - 1, j = 0; i >= 0 && j < arrSize; i--, j++)
    {
        desc_array[j] = i + 1;
    }
    srand(time(NULL));
    for (int i = 0; i < arrSize; i++)
    {
        random_array[i] = rand() % 100;
    }

    clock_t startTime, endTime;
    double cpuTimeUsed;

    printf("Best Case:\n");
    printf("Input array: ");
    // printArray(asc_array, arrSize);
    startTime = clock();
    insertionSort(asc_array, arrSize);
    endTime = clock();
    printf("Output array: ");
    // printArray(asc_array, arrSize);
    printf("Number of moves = %ld\n", totalMoves);
    printf("Number of operations = %ld\n", totalOperations);
    cpuTimeUsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpuTimeUsed);

    printf("\nAverage Case:\n");
    totalMoves = 0;
    totalOperations = 0;
    printf("Input array: ");
    // printArray(random_array, arrSize);
    startTime = clock();
    insertionSort(random_array, arrSize);
    endTime = clock();
    printf("Output array: ");
    // printArray(random_array, arrSize);
    printf("Number of moves = %ld\n", totalMoves);
    printf("Number of operations = %ld\n", totalOperations);
    cpuTimeUsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpuTimeUsed);

    printf("\nWorst Case:\n");
    totalMoves = 0;
    totalOperations = 0;
    printf("Input array: ");
    // printArray(desc_array, arrSize);
    startTime = clock();
    insertionSort(desc_array, arrSize);
    endTime = clock();
    printf("Output array: ");
    // printArray(desc_array, arrSize);
    printf("Number of moves = %ld\n", totalMoves);
    printf("Number of operations = %ld\n", totalOperations);
    cpuTimeUsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpuTimeUsed);

    return 0;
}