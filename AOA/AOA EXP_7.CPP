#include <stdio.h>
#include <string.h>

int i, j, m, n;
int c[21][21];
char x[21], y[21];
char b[21][21];

void print_lcs(int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == 'c')
    {
        print_lcs(i - 1, j - 1);
        printf("%c", x[i - 1]);
    }
    else if (b[i][j] == 'u')
    {
        print_lcs(i - 1, j);
    }
    else
    {
        print_lcs(i, j - 1);
    }
}

void lcs_length()
{
    m = strlen(x);
    n = strlen(y);

    for (i = 0; i <= m; i++)
        c[i][0] = 0;

    for (j = 0; j <= n; j++)
        c[0][j] = 0;

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'c'; 
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';  
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';  
            }
        }
    }
}

int main()
{
    printf("Enter 1st sequence: ");
    scanf("%s", x);

    printf("Enter 2nd sequence: ");
    scanf("%s", y);

    lcs_length();

    printf("\nThe Longest Common Subsequence is: ");
    print_lcs(m, n);

    printf("\nLength of LCS = %d\n", c[m][n]);

    return 0;
}