#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

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
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
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

int main()
{
    clock_t start, end;
    double t = 0;
    int asc[SIZE], desc[SIZE], rand_arr[SIZE];

    for (int i = 0; i < SIZE; i++)
        asc[i] = i;

    for (int i = 0; i < SIZE; i++)
        desc[i] = SIZE - i - 1;

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
        rand_arr[i] = rand() % 100;

    printf("Begin sorting----------\n");
    printf("Size: %d\n", SIZE);


    printf("First 10 elements of BEST-CASE array: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", asc[i]);
    }
    printf("\n");
    start = clock();
    mergeSort(asc, 0, SIZE - 1);
    end = clock();
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", asc[i]);
    }
    printf("\n");

    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nBEST CASE: %lf\n", t);

    printf("First 10 elements of WORST-CASE array: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", desc[i]);
    }
    printf("\n");
    start = clock();
    mergeSort(desc, 0, SIZE - 1);
    end = clock();
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", desc[i]);
    }
    printf("\n");
    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("WORST CASE: %lf\n", t);

    printf("First 10 elements of AVG-CASE array: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", rand_arr[i]);
    }
    printf("\n");
    start = clock();
    mergeSort(rand_arr, 0, SIZE - 1);
    end = clock();
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", rand_arr[i]);
    }
    printf("\n");
    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("AVERAGE CASE: %lf\n", t);

    return 0;
}