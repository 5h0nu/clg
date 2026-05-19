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


//3rd  A program

#include <stdio.h>

int main() {
    int a[10][10], n;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter graph data:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    // Floyd-Warshall Algorithm
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];

    printf("\nShortest path matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}


// 3 B 

#include <stdio.h>

int main() {
    int a[10][10], n;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter graph data:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    // Warshall's Algorithm
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);

    printf("\nResultant path matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}

// program 4 

#include <stdio.h>

int main() {
    int c[10][10], d[10], v[10] = {0}, n, s, u, min;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter graph data:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);

    printf("Enter source node: ");
    scanf("%d", &s);

    // Initialization
    for (int i = 1; i <= n; i++) d[i] = c[s][i];
    v[s] = 1;

    // Dijkstra's Algorithm
    for (int i = 1; i < n; i++) {
        min = 999;
        for (int j = 1; j <= n; j++)
            if (!v[j] && d[j] < min) { min = d[j]; u = j; }
            
        v[u] = 1;
        for (int j = 1; j <= n; j++)
            if (!v[j] && (d[u] + c[u][j] < d[j])) d[j] = d[u] + c[u][j];
    }

    printf("\nShortest distances from source node %d:\n", s);
    for (int i = 1; i <= n; i++) printf("Node %d: %d\n", i, d[i]);
}



// pro 5

#include<stdio.h>
int temp[10], k = 0;
void sort(int a[10][10], int id[10], int n)
{
 int i, j;
 for (i = 1; i <= n; i++)
 {
 if (id[i] == 0)
 {
 id[i] = -1;
 temp[++k] = i;
 for (j = 1; j <= n; j++)
 {
 if (a[i][j] == 1 && id[j] != -1)
 id[j]--;
 }
 i = 0;
 }
 }
}
void main()
{
 int a[10][10], id[10], n, i, j;
 // clrscr();
 printf("\nEnter the n value: ");
 scanf("%d", &n);
 for (i = 1; i <= n; i++)
 id[i] = 0;
 printf("\nEnter the graph data:\n");
 for (i = 1; i <= n; i++)
 for (j = 1; j <= n; j++)
 {
 scanf("%d", &a[i][j]);
 if (a[i][j] == 1)
 id[j]++;
 }
sort(a, id, n);
 if (k != n)
 printf("\nTopological ordering not possible");
 else
 {
 printf("\nTopological ordering is: ");
 for (i = 1; i <= k; i++)
 printf("%d ", temp[i]);
 }
}


// pog 6

#include <stdio.h>
int w[10], p[10], n;
int max(int a, int b) {
 return a > b ? a : b;
}
int knap(int i, int m) {
 if (i == n) return w[i] > m ? 0 : p[i];
 if (w[i] > m) return knap(i + 1, m);
 return max(knap(i + 1, m), knap(i + 1, m - w[i]) + p[i]);
}
void main() {
 int m, i, max_profit;
 printf("\nEnter the no. of objects: ");
 scanf("%d", &n);
 printf("\nEnter the knapsack capacity: ");
 scanf("%d", &m);
 printf("\nEnter profit followed by weight:\n");
 for (i = 1; i <= n; i++)
 scanf("%d %d", &p[i], &w[i]);
 max_profit = knap(1, m);
 printf("\nMax profit = %d\n", max_profit);
 
}
