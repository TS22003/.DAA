#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void main()
{
    int graph[MAX][MAX], indeg[MAX] = {0}, n, i, j, count = 0, stack[MAX], top = -1, node;
    printf("\nEnter the number of nodes in the graph:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            indeg[i] += graph[j][i];

    for (i = 0; i < n; i++)
        if (indeg[i] == 0)
            stack[++top] = i;

    if(top<0)
        printf("No source found\n");
    else{
    printf("\nThe topological order is:\n");
    while (top != -1)
    {
        node = stack[top--];
        printf(" => %c", node + 65);
        for (i = 0; i < n; i++)
        {
            if (graph[node][i])
            {
                graph[node][i] = 0;
                indeg[i]--;
                if (indeg[i] == 0)
                    stack[++top] = i;
            }
        }
    }
}
}
