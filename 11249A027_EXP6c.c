#include <stdio.h>
#define V 3
#define INF 9999

void floyd(int b[V][V]) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (b[i][k] + b[k][j] < b[i][j])
                    b[i][j] = b[i][k] + b[k][j];

    printf("Shortest distance matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%d\t", b[i][j]);
        printf("\n");
    }
}

int main() {
    int b[V][V] = {
        {0, 10, INF},
        {INF, 0, 15},
        {12, INF, 0}
    };

    floyd(b);
    return 0;
}
