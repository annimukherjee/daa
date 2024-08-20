// #include <stdio.h>

// // Best case: Sorted in Ascending Order
// // Average case: random numbers
// // Worst case: Sorted in descending order

// int main()
// {
//     int n;
//     printf("Enter the size of the array: \n");
//     scanf("%d", &n);

//     int arr[n];

//     printf("// Best case: Sorted in Ascending Order\n// Average case: random numbers\n// Worst case: Sorted in descending order\n\n----\n");
//     printf("Enter the elements of the array of size %d :-\n", n);
//     for(int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     int i, key, j;
//     for (i = 1; i < n; i++)
//     {
//         key = arr[i];
//         j = i - 1;

//         // Move elements of arr[0..i-1],
//         // that are greater than key,
//         // to one position ahead of their
//         // current position
//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n, int *stepCount)
{
    int i, key, j;
    *stepCount = 0;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*stepCount)++;
        }
        arr[j + 1] = key;
    }
}

void generateAscending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

void generateDescending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i - 1;
    }
}

void generateRandom(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
}

void runTest(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    int stepCount;

    printf("Array size: %d\n", n);

    // Best case: Sorted in Ascending Order
    generateAscending(arr, n);
    insertionSort(arr, n, &stepCount);
    printf("Best case (Ascending): %d steps\n", stepCount);

    // Average case: Random numbers
    generateRandom(arr, n);
    insertionSort(arr, n, &stepCount);
    printf("Average case (Random): %d steps\n", stepCount);

    // Worst case: Sorted in Descending Order
    generateDescending(arr, n);
    insertionSort(arr, n, &stepCount);
    printf("Worst case (Descending): %d steps\n", stepCount);

    printf("\n");
    free(arr);
}

int main()
{
    srand(time(NULL));
    int sizes[] = {10, 100, 4000, 10000};
    // int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int size_ix = 0; size_ix < 4; size_ix++)
    {
        int asc_arr[sizes[size_ix]];
        for (int i = 0; i < n; i++)
        {
            asc_arr[i] = i;
        }

        int desc_arr[sizes[size_ix]];
        for (int i = 0; i < n; i++)
        {
            desc_arr[i] = n - i - 1;
        }

        
    }

    // for (int i = 0; i < numSizes; i++) {
    //     runTest(sizes[i]);
    // }

    return 0;
}