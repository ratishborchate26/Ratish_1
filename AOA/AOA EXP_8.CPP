#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int board[20];
int solutionCount = 0;

int place(int row, int column) {
    for (int i = 1; i < row; i++) {
        if (board[i] == column)
            return 0;

        if (abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1;
}

void solveNQueen(int row, int n) {
    for (int column = 1; column <= n; column++) {
        if (place(row, column)) {
            board[row] = column;

            if (row == n) {
                solutionCount++;
                printf("\nSolution %d:\n", solutionCount);

                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (board[i] == j)
                            printf("Q\t");
                        else
                            printf("*\t");
                    }
                    printf("\n");
                }
            }
            else {
                solveNQueen(row + 1, n);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Number of queens must be between 1 and 20\n");
        return 0;
    }

    solveNQueen(1, n);

    if (solutionCount == 0)
        printf("\nNo solution exists\n");
    else
        printf("\nTotal solutions = %d\n", solutionCount);

    return 0;
}