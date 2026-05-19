#include <stdio.h>

int main() {
    int n, min, a, b, ne = 1, mincost = 0;
    int cost[20][20], visited[20] = {1}; // Start with vertex 0 visited, rest 0

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter cost adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("\nThe edges of the Spanning Tree are:\n");
    while (ne < n) {
        min = 999;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) continue;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && cost[i][j] > 0 && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i; b = j;
                }
            }
        }
        visited[b] = 1;
        mincost += min;
        printf("Edge %d: (%d -> %d) = %d\n", ne++, a, b, min);
    }
    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}




// program 2

#include <stdio.h>

int main() {
    int n, min, a, b, ne = 1, mincost = 0;
    int cost[10][10], visited[10] = {0, 1}; // Start with node 1 visited

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = 999;
        }

    while (ne < n) {
        min = 999;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) continue;
            for (int j = 1; j <= n; j++) {
                if (!visited[j] && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i; b = j;
                }
            }
        }
        printf("\n Edge %d:(%d %d) cost:%d", ne++, a, b, min);
        mincost += min;
        visited[b] = 1;
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n Minimum cost=%d\n", mincost);
    return 0;
}
