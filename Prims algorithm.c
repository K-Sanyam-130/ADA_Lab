#include <stdio.h>

#define MAX 10
#define INF 99999

// Function to find the vertex with minimum key value
int minKey(int key[], int mstSet[], int n)
{
    int min = INF, min_index;

    for (int v = 0; v < n; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the MST
void printMST(int parent[], int graph[MAX][MAX], int n)
{
    int totalCost = 0;

    printf("\nEdge \tWeight\n");

    for (int i = 1; i < n; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }

    printf("\nMinimum Cost = %d\n", totalCost);
}

// Prim's Algorithm
void primMST(int graph[MAX][MAX], int n)
{
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    // Initialize arrays
    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        mstSet[i] = 0;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet, n);

        mstSet[u] = 1;

        // Update adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);
}

int main()
{
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nPrim's Algorithm - Minimum Cost Spanning Tree\n");

    primMST(graph, n);

    return 0;
}
