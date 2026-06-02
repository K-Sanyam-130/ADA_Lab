#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = 0;

void topologicalSort(int n)
{
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (adj[j][i])
                indegree[i]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    printf("Topological Order: ");

    while (front < rear)
    {
        int u = queue[front++];
        printf("%d ", u);

        for (int v = 0; v < n; v++)
        {
            if (adj[u][v])
            {
                indegree[v]--;

                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }

        count++;
    }

    if (count != n)
        printf("\nGraph contains a cycle.\n");
}

int main()
{
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (u v) meaning u -> v:\n");

    for (int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort(n);

    return 0;
}
