#include<stdio.h>

int main() {
    int N;
    printf("Enter the size n of array : ");
    scanf("%d", &N);
    
    int arr[N];
    printf("\nEnter the elements of the array of size %d :-\n", N);
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum[N];
    int termsOfPrefixSum = 0;
    for(int i = 0; i < N; i++) {
        termsOfPrefixSum = termsOfPrefixSum + arr[i];
        prefixSum[i] = termsOfPrefixSum;
    }
    printf("\nInput Array: ");
    for(int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nOutput Array: ");
    
    for(int i = 0; i < N; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");
}