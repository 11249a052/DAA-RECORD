#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void printResult(char *name, int bins) {
    printf("\n%s\nTotal bins used: %d\n", name, bins);
}

// ---------------- FIRST FIT ----------------
void firstFit(int w[], int n, int cap) {
    int bin[MAX] = {0};
    int used = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < used; j++) {
            if (bin[j] >= w[i]) {
                bin[j] -= w[i];
                break;
            }
        }

        if (j == used) {
            bin[used] = cap - w[i];
            used++;
        }
    }

    printResult("First Fit:", used);
}

// ---------------- BEST FIT ----------------
void bestFit(int w[], int n, int cap) {
    int bin[MAX] = {0};
    int used = 0;
    int i, j;
    int best, min;

    for (i = 0; i < n; i++) {
        best = -1;
        min = cap + 1;

        for (j = 0; j < used; j++) {
            if (bin[j] >= w[i] && (bin[j] - w[i]) < min) {
                best = j;
                min = bin[j] - w[i];
            }
        }

        if (best != -1) {
            bin[best] -= w[i];
        } else {
            bin[used] = cap - w[i];
            used++;
        }
    }

    printResult("Best Fit:", used);
}

// ----------- FIRST FIT DECREASING ----------
int cmp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

void firstFitDecreasing(int w[], int n, int cap) {
    int temp[MAX];
    int i;

    for (i = 0; i < n; i++) {
        temp[i] = w[i];
    }

    qsort(temp, n, sizeof(int), cmp);
    firstFit(temp, n, cap);
}

// ---------------- MAIN ----------------
int main() {
    int n, cap;
    int w[MAX];
    int i;

    printf("Enter number of items and bin capacity: ");
    scanf("%d %d", &n, &cap);

    printf("Enter item weights:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    firstFit(w, n, cap);
    firstFitDecreasing(w, n, cap);
    bestFit(w, n, cap);

    return 0;
}
