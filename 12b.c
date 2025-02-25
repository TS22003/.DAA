//floyd
//test
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int graph[MAX][MAX];

int minimum (int a, int b) {
    int min = (a<b) ? a : b;
    return min;
}
int count=0
void floyd (int n) {
    int t;
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
              t=graph[i][k];
            for(int j=1; j<=n; j++) {
                if(t<graph[i][j])
                {
                    count++;
                graph[i][j] = minimum(graph[i][j], (graph[i][k] + graph[k][j]));
                }
            }
        }
    }
}

void main() {
    int n, i, j;
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);
    printf("\nEnter 99999 for representing infinity.\n");
    printf("\nEnter the weight matrix:\n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floyd(n);

    printf("\nAll pair shortest distance matrix is:\n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}
