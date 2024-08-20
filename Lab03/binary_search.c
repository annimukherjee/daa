#include <stdio.h>
#include <time.h>
#define g 50000

int binarysearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    clock_t start, end;
    int arr1[g];
    for (int i = 0; i < g; i++)
    {
        arr1[i] = i;
    }

    start = clock();
    int a = binarysearch(arr1, 0, g - 1, 67);
    end = clock();

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Used in sec: %f\n", cpu_time_used);

    if (a != -1)
        printf("Element found at index: %d\n", a);
    else
        printf("Element not found\n");

    return 0;
}