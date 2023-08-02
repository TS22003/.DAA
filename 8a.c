#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int count = 0, order = 0, cyclic = 0, n;
int visited[MAX] = {0}, graph[MAX][MAX];

void bfs(int start)
{
    int queue[MAX], parent[MAX], parentnode, rear = 0, front = -1;
    count++;
    visited[start] = 1;
    queue[rear] = start;
    parent[rear] = -1;
    while (rear != front)
    {
        front++;
        start = queue[front];
        parentnode = parent[front];
        printf("--> %d ", start);
        for (int i = 0; i < n; i++)
        {
            order++;
            if (i != parentnode && graph[start][i] && visited[i])
                cyclic = 1;
            if (graph[start][i] && !visited[i])
            {
                rear++;
                queue[rear] = i;
                parent[rear] = start;
                visited[i] = 1;
                count++;
            }
        }
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
    printf("\nBreadth First Search Traversal: \nStarting Node: %d\n", start);
    bfs(start);
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
                bfs(start);
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
