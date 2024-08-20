#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float ratio;
    int weight;
} Item;

int compare(const void* a, const void* b) {
    return ((Item*)b)->ratio > ((Item*)a)->ratio ? 1 : -1;
}

float fractionalKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);

    float totalValue = 0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].ratio * items[i].weight;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].ratio * remainingWeight;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    Item* items = malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        float value;
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%f %d", &value, &items[i].weight);
        items[i].ratio = value / items[i].weight;
    }

    float maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    free(items);
    return 0;
}