#include <stdio.h>

void rotateRight(int arr[], int size);
void exchange(int* p, int* q);

int main()
{
    int a[9] = {11, 22, 33, 44, 55, 66, 77, 88, 99};

    printf("\n---------\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);
    }

    rotateRight(a, 5);

    printf("\n---------\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

// void exchange(int p, int q)
// {

// }

void exchange(int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Function definition
void rotateRight(int arr[], int m)
{

    

    for (int i = m - 2; i >= 0; i--)
    {
        /* code */
        exchange(arr + i, arr + i + 1);

        // int temp = arr[i];
        // arr[i] = arr[i + 1];
        // arr[i + 1] = temp;
    }

    // int ele_first = arr[m-1];

    // for (int i = m - 1; i > 0; i--)
    // {
    //     arr[i] = arr[i - 1];
    // }

    // arr[0] = ele_first;


    // 11 22 33 44 55 66 77 88 99 


}
