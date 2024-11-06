#include <stdio.h>
#include <math.h>

void heapify(int a[], int n, int i);
void heap_sort(int a[], int n);


void heapify(int a[], int n, int i)
{
    int largest_idx = i;       // largest_idx is initially the root
    int left_idx = (2 * i) + 1;  // left child
    int right_idx = (2 * i) + 2; // right child
    
    
    // If left_idx child is larger than root
    // first assign the largest_idx element as the left child's index, then compare with right child's index, if right child
    // is more, then make that the largest_idx.

    // at the end, check if the largest_idx is unchanged, i.e. the index of largest_idx is still same a root, then don't do anything
    // else, swap the root with the largest_idx element

    if ((left_idx < n) && (a[left_idx] < a[largest_idx]))
        largest_idx = left_idx;
    
    if ((right_idx < n) && (a[right_idx] < a[largest_idx]))
        largest_idx = right_idx;
    

    // If root not i (i.e. the root...)
    if (largest_idx != i)
    {
        // swap a[i] <---> a[largest_idx]
        int temp = a[i];
        a[i] = a[largest_idx];
        a[largest_idx] = temp;

        heapify(a, n, largest_idx);
    }
}

void heap_sort(int a[], int n)
{   

    // array elements from n/2 to the end are leaf nodes. 
    // we need to ensure that the elements below this element are max-heaps

    // so, we call "heapify" on all nodes which aren't leaf nodes which is basically (n/2 - 1)
    // this ensures every sub-tree is a max-heap and thus the entire tree is a max-heap.

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);


    // we traverse every elements from the end i.e. the leaf and swap the root element with the 
    // element we are traversing and do heapify. this ensures that we have the largest element in the root after 

    for (int i = n - 1; i >= 0; i--)
    {
        // array is already in max-heap. So root is the largest node in the array that hasn't been removed...
        // so we know the root is the largest element, so we move it to the back of the array, and move the last node at the leaf
        // to the root and do heapify to get a heap-structure.
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        printf("[ ");
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("]\n");

        heapify(a, i, 0);
    }
}


void extract_max(int a[], int* n)
{
    if(*n <= 0)
    {
        printf("Heap is empty\n");
        return;
    }

    

    a[0] = a[*n - 1];
    *n = *n - 1;

    heapify(a, *n, 0);

    int max = a[0];

    printf("Extracted max: %d\n", max);
}

void insert_heap(int a[], int x, int* n)
{
    *n = *n+1;

    int i = *(n) -1;

    a[i] = x;

    while (a[i] > a[(int)floor((i)/2.0)] && i>1)
    {
        int temp = a[i];
        a[i] = a[(int)floor(i/2)];
        a[(int)floor(i/2)] = temp;

        i = (int)floor(i/2);

    }
    


}

int main()
{
    // int a[100] = {54, 16, 28, 46, 18, 96, 1};
    int a[100] = {7,5,10,1,4};
    int n = 5;

    printf("Before sorting array elements are - \n");
    printf("[ ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("]\n--------\n");


    heap_sort(a, n);
    
    printf("\nAfter sorting array elements are - \n");
    printf("[ ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("]\n");

    // Demonstrating extract_max function
    printf("\nDemonstrating extract_max function:\n");
    extract_max(a, &n);
    printf("Array after extracting max: [ ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("]\n");

    // Demonstrating insert_heap function
    printf("\nDemonstrating insert_heap function:\n");
    int new_element = 8;
    printf("Inserting element: %d\n", new_element);
    insert_heap(a, new_element, &n);
    printf("Array after insertion: [ ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("]\n");

    return 0;
}