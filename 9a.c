#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int count;
int top = -1, stack[MAX];
void dfs(int graph[][MAX], int visited[], int n, int start)
{
    visited[start] = 1;
    for (int i = 0; i < n; i++)
    {
        count++;
        if (graph[start][i] && visited[i] == 0)
            dfs(graph, visited, n, i);
    }
    stack[++top] = start;
}
void main()
{
    int graph[MAX][MAX], visited[MAX] = {0}, n, i, j;
    printf("\nEnter the number of nodes in the graph:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("\nThe topological order is:\n");
    for (int i = 0; i < n; i++)
    {
        count++;
        if (visited[i] == 0)
            dfs(graph, visited, n, i);
    }
    while (top != -1)
        printf("%d -> ", stack[top--]);
    printf("\nCount : %d \n", count);
}
