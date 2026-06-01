#include <stdio.h>

int mobile(int p[], int d[], int n)
{
    int m = 0;

    for (int i = 0; i < n; i++)
    {
        if (d[i] == -1 && i > 0 && p[i] > p[i - 1] && p[i] > m)
        {
            m = p[i];
        }

        if (d[i] == 1 && i < n - 1 && p[i] > p[i + 1] && p[i] > m)
        {
            m = p[i];
        }
    }

    return m;
}

int main()
{
    int n;
    int p[10], d[10];
    int i, m, pos, next, temp;

    printf("Enter n: ");
    scanf("%d", &n);

    /* Initialize permutation and directions */
    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;
        d[i] = -1;   // All directions initially point left
    }

    while (1)
    {
        /* Print directions */
        for (i = 0; i < n; i++)
        {
            printf("%3c", (d[i] == -1) ? '<' : '>');
        }
        printf("\n");

        /* Print permutation */
        for (i = 0; i < n; i++)
        {
            printf("%3d", p[i]);
        }
        printf("\n\n");

        /* Find largest mobile element */
        m = mobile(p, d, n);

        /* Stop when no mobile element exists */
        if (m == 0)
        {
            break;
        }

        /* Find position of largest mobile element */
        for (i = 0; i < n; i++)
        {
            if (p[i] == m)
            {
                pos = i;
                break;
            }
        }

        /* Find the adjacent position in its direction */
        next = pos + d[pos];

        /* Swap numbers */
        temp = p[pos];
        p[pos] = p[next];
        p[next] = temp;

        /* Swap directions */
        temp = d[pos];
        d[pos] = d[next];
        d[next] = temp;

        /* Reverse directions of all elements larger than m */
        for (i = 0; i < n; i++)
        {
            if (p[i] > m)
            {
                d[i] = -d[i];
            }
        }
    }

    return 0;
}