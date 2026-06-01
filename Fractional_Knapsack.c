#include <stdio.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

// Sort items by ratio in descending order
void sort(struct Item items[], int n) {
    int i, j;
    struct Item temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

// Fractional Knapsack function
float fractionalKnapsack(struct Item items[], int n, int capacity) {
    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].ratio * capacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter no. of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter value and weight:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);

        // Avoid division by zero
        if (items[i].weight != 0)
            items[i].ratio = (float)items[i].value / items[i].weight;
        else
            items[i].ratio = 0;
    }

    printf("Enter the capacity: ");
    scanf("%d", &capacity);

    sort(items, n);

    float maxValue = fractionalKnapsack(items, n, capacity);

    printf("Maximum profit = %.2f\n", maxValue);

    return 0;
}