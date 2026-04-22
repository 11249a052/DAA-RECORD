#include <stdio.h>
#include <limits.h>
#define V 5
int minKey(int key[], int mst[]) {
    int i, min = INT_MAX, idx;
    for (i = 0; i < V; i++)
        if (!mst[i] && key[i] < min)
            min = key[i], idx = i;
    return idx;
}
void prim(int g[V][V]) {
    int parent[V], key[V], mst[V];
    int i, v, u;
    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mst[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (i = 0; i < V - 1; i++) {
        u = minKey(key, mst);
        mst[u] = 1;
        for (v = 0; v < V; v++)
            if (g[u][v] && !mst[v] && g[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g[u][v];
            }
    }
    for (i = 1; i < V; i++)
        printf("%d-%d %d\n", parent[i], i, g[parent[i]][i]);
}
int main() {
    int g[V][V] = {
        {0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}
    };
    prim(g);
    return 0;
}
