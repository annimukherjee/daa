#include<stdio.h>

int main() {
    printf("Input:\n");
    int n;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array of size %d :-\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int max = arr[0];
   
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    
    int freq[max+1];
    for(int i = 0; i <= max; i++) {
        freq[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    int numberOfDuplicateElements = 0;
    int mostRepeatingElement = 0;
    for(int i = 0; i <= max; i++) {
        if(freq[i] > 1) {
            numberOfDuplicateElements++;
        }
        if(freq[i] > 0 && freq[i] > freq[mostRepeatingElement]) {
            mostRepeatingElement = i;
        }
    }
    printf("\n\nOutput:");
    printf("\nThe content of the array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTotal number of duplicate values = %d", numberOfDuplicateElements);
    printf("\nThe most repeating element in the array = %d", mostRepeatingElement);
}