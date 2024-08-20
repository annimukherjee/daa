#include<stdio.h>




int main() {
    int n;
    printf("Enter the size n of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements of the array of size %d :-\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = -999999, min = 99999;

    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        } else if(arr[i] < min) {
            min = arr[i];
        }
    }
    int secondLargest = min, secondSmallest = max;
    for(int i = 0; i < n; i++) {
        if(arr[i] > secondLargest && arr[i] != max) {
            secondLargest = arr[i];
        }
        if(arr[i] < secondSmallest && arr[i] != min) {
            secondSmallest = arr[i];
        }
    }
    printf("\nSecond Largest = %d", secondLargest);
    printf("\nSecond Smallest = %d", secondSmallest);
}