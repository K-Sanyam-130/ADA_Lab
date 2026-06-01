#include <stdio.h>
#include <stdlib.h>

int x[20];
int sol = 0;

int place(int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if (x[j] == i || abs(j - k) == abs(x[j] - i))
        {
            return 0;
        }
    }
    return 1;
}

void NQueens(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;

            if (k == n)
            {
                sol++;
                printf("\nSolution %d:\n", sol);

                for (int row = 1; row <= n; row++)
                {
                    for (int col = 1; col <= n; col++)
                    {
                        if (x[row] == col)
                            printf("Q ");
                        else
                            printf(". ");
                    }
                    printf("\n");
                }
            }
            else
            {
                NQueens(k + 1, n);
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    NQueens(1, n);

    printf("\nTotal solutions = %d\n", sol);

    return 0;
}