#include <stdio.h>
#include <stdlib.h>

// Structure to store item details
struct Item {
    int profit;
    int weight;
    float ratio;
};

// Comparator function for qsort (sort in descending order of ratio)
int compare(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;

    if (itemB->ratio > itemA->ratio)
        return 1;
    else if (itemB->ratio < itemA->ratio)
        return -1;
    else
        return 0;
}

int main() {
    int n, capacity;
    float totalProfit = 0.0;
    int i;   // ? Declared outside loop

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    printf("Enter profit and weight of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &item[i].profit, &item[i].weight);

        if (item[i].weight != 0)
            item[i].ratio = (float)item[i].profit / item[i].weight;
        else
            item[i].ratio = 0;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items by decreasing profit/weight ratio
    qsort(item, n, sizeof(struct Item), compare);

    printf("\nItems selected:\n");

    for (i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (capacity >= item[i].weight) {
            printf("Item with profit %d and weight %d taken fully\n",
                   item[i].profit, item[i].weight);

            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        } else {
            printf("Item with profit %d and weight %d taken partially\n",
                   item[i].profit, item[i].weight);

            totalProfit += item[i].profit *
                           ((float)capacity / item[i].weight);
            capacity = 0;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
