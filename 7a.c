#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int count = 0, order = 0, cyclic = 0, n;
int visited[MAX] = {0}, graph[MAX][MAX];
void dfs(int v, int prev)
{
    count++;
    visited[v] = 1;
    printf("--> %d ", v);
    for (int i = 0; i < n; i++)
    {
        order++;
        if (i != prev && graph[v][i] && visited[i])
            cyclic = 1;
        if (graph[v][i] && !visited[i])
            dfs(i, v);
    }
}

void main()
{
    int i, j, start;
    printf("Enter the number of nodes : \n");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix : \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter the starting vertex : \n");
    scanf("%d", &start);
    printf("\nDepth First Search Traversal: \nStarting Node: %d\n", start);
    dfs(start, -1);
    if (count == n)
        printf("\nGraph is connected");
    else
    {
        printf("\nThe graph is not connected");
        start = 0;
        while (count != n)
        {
            if (visited[start] != 1)
            {
                printf("\nStarting Node: : %d\n", start);
                dfs(start, -1);
            }
            start++;
        }
    }
    if (cyclic == 0)
        printf("\nGraph is Acyclic\n");
    else
        printf("\nGraph is Cyclic\n");
    printf("Order of count : %d\n", order);
}
