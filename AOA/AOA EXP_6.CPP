#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, M, i, j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int w[n + 1], v[n + 1];

    printf("Enter weights of items:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }

    printf("Enter profits of items:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &v[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &M);

    int V[n + 1][M + 1];

    for (i = 0; i <= n; i++)
        V[i][0] = 0;

    for (j = 0; j <= M; j++)
        V[0][j] = 0;

    
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= M; j++)
        {
            if (w[i] <= j)
                V[i][j] = max(V[i - 1][j], v[i] + V[i - 1][j - w[i]]);
            else
                V[i][j] = V[i - 1][j];
        }
    }

    printf("\nMaximum Profit = %d\n", V[n][M]);


    printf("Items included:\n");

    i = n;
    j = M;

    while (i > 0 && j > 0)
    {
        if (V[i][j] != V[i - 1][j])
        {
            printf("Item %d (Weight = %d, Profit = %d)\n", i, w[i], v[i]);
            j = j - w[i];
        }
        i--;
    }

    return 0;
}