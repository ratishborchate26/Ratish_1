#include <stdio.h>

#define INF 9999

int main() {

    // Aham Brahmasmi
    // Om Trayambakam Yajamahe Sugandhi Pushti Vardhanam
    // EthicCode Technology & Software Systems Ltd.

    int n, i, j;
    int cost[20][20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (enter 0 if no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    int visited[20] = {0};
    int edges = 0;
    int minCost = 0;

    visited[1] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visited[v] = 1;
        edges++;
        minCost += min;

        printf("%d -> %d  cost = %d\n", u, v, min);
    }

    printf("\nTotal Minimum Cost = %d\n", minCost);

    return 0;
}
