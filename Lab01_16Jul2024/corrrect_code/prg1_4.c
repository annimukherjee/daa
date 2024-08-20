#include<stdio.h>
#include<stdlib.h>

void exchange(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void rotate_right(int p1[], int p2) {
    //int size = sizeof(p1) / sizeof(p1[0]);  //here p1 has become a pointer since array decays to pointer when passed as a parameter
    for(int i = 8; i > 0; i--) {
        if(i < p2) {
            exchange(&p1[i], &p1[i-1]);
        }
    }
} 

int main() {
    int n;
    printf("Enter the size n of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter an array A of size %d :-\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int p2;
    printf("Enter the value of p2 : ");
    scanf("%d", &p2);
    rotate_right(arr, p2);
    //int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < n; i++) {
        printf("%d " , arr[i]);
    }
}