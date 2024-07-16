#include <stdio.h>

int main()
{
    int arr[5] = {3, 4, 5, 1, 2};

    for (int i = 1; i < 5; i++)
    {
        arr[i] = arr[i-1] + arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    
    
    return 0;
}