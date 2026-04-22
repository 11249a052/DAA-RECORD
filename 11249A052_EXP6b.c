#include <stdio.h>
#include <limits.h>

#define V 6
int i,u,v;
int graph[V][V] = {
    {0,10,0,15,0,0},
    {0,0,0,5,10,0},
    {0,0,0,0,0,10},
    {0,0,0,0,0,5},
    {0,0,0,0,0,10},
    {0,0,0,0,0,0}
};

void bellmanFord(int src) {
    int dist[V];
    

    for (i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (i = 0; i < V - 1; i++)
        for (u = 0; u < V; u++)
            for (v = 0; v < V; v++)
                if (graph[u][v] && dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            if (graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                printf("Negative cycle detected\n");
                return;
            }

    printf("Vertex\tDistance\n");
    for (i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i] == INT_MAX ? -1 : dist[i]);
}

int main() {
    bellmanFord(0);
    return 0;
}
#THE END
