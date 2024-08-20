#include <stdio.h>
void heapify(int a[], int n, int i);
void heap_sort(int a[], int n);


void heapify(int a[], int n, int i)
{
    int largest = i;       // largest is root
    int l = (2 * i) + 1;  // left child
    int r = (2 * i) + 2; // right child
    
    // If l child is larger than root
    if ((l < n) && (a[l] > a[largest]))
        largest = l;
    
    // If r child is larger than root
    if ((r < n) && (a[r] > a[largest]))
        largest = r;
    
    // Ifroot not largest
    if (largest != i)
    {
        // swap a[i] <---> a[largest]
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // extract an element from heap one by one
    for (int i = n - 1; i >= 0; i--)
    {
        /* Move curr root element to end*/
        // swap a[0] <---> a[i]
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}


int main()
{
    int a[] = {48, 10, 23, 43, 28, 26, 1};
    int n = 7;

    printf("Before sorting array elements are - \n");
    printf("[ ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("]\n");


    heap_sort(a, n);
    
    printf("\nAfter sorting array elements are - \n");
    printf("[ ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("]\n");

    return 0;
}