//Test

/*program to implement the topological sorting with dsource removal method on adjacency matrix*/
#include <stdio.h> 
 #include <stdlib.h> 
 // LEgend 
 int a[100][100]; 
 int in[100], v[100], s[100], t[100]; // 
 int f = 0, r = -1;                   // 
 int n, scount = 0; 
 computeindegree() 
 { 
     for (int i = 0; i < n; i++) 
     { 
         in[i] = 0; 
         v[i] = 0; 
     } 
     for (int i = 0; i < n; i++) 
     { 
         for (int j = 0; j < n; j++) 
         { 
             if (a[j][i] == 1) 
             { 
                 in[i]++; 
             } 
         } 
         // printf("%d\t%d\n", i, in[i]); 
         if (in[i] == 0) 
         { 
             // printf("\n%d", i); 
             scount++; 
             s[++r] = i; 
             v[i] = 1; 
         } 
     } 
 } 
 void topo() 
 { 
     int cnt = 0; 
     while (scount != 0) 
     { 
         int src = s[f++]; 
         scount--; 
         t[cnt] = src; 
         cnt++; 
         for (int i = 0; i < n; i++) 
         { 
             if (a[src][i] == 1) 
             { 
                 in[i]--; 
             } 
             if (in[i] == 0 && v[i] == 0) 
             { 
                 scount++; 
                 v[i] = 1; 
                 s[++r] = i; 
             } 
         } 
     } 
     if (cnt != n) 
     { 
         printf("Cycle Exist"); 
     } 
     else 
     { 
         printf("\nThe topological sorting is\n"); 
         for (int i = 0; i < n; i++) 
             printf("%d\t", t[i] + 1); 
     } 
 } 
 void main() 
 { 
     int i, j; 
     printf("enter the number of vertices:"); 
     scanf("%d", &n); 
  
     printf("Enter the adjacency matrix:\n"); 
     for (i = 0; i < n; i++) 
     { 
         for (j = 0; j < n; j++) 
         { 
             scanf("%d", &a[i][j]); 
         } 
     } 
     computeindegree(); 
     topo(); 
 }
// another method
#include<stdio.h>
#include<stdlib.h>
  int count=0;

typedef struct queue
{
int f,r,*arr,cnt;
}QUE;

int s[10];

 void indegree(int *a[],int v,int inq[],QUE *temp,int flag[])
{
       for(int i=0;i<v;i++)
     {
       for(int j=0;j<v;j++)
       {
         if(a[j][i]==1)
        inq[i]=inq[i]+1;
       }
          if(inq[i]==0)
          {
            temp->r=(temp->r+1)%v;
             temp->arr[temp->r]=i;
             temp->cnt=temp->cnt+1;
              flag[i]=1;
            }
       }
}

void sourceremove(int *a[],int v,QUE *temp,int inq[],int flag[])
{
int cnt=0; 
while(temp->cnt!=0)
{
  int source=temp->arr[temp->f]; 
   temp->f=(temp->f+1)%v;
   s[cnt]=source;
   temp->cnt=temp->cnt-1; 
    cnt++;
   for(int i=0;i<v;i++)
  {  
    if(a[source][i]==1)
      inq[i]=inq[i]-1; 
      if(inq[i]==0&&flag[i]==0)
     {
       temp->r=(temp->r+1)%v; 
       temp->arr[temp->r]=i; 
       temp->cnt=temp->cnt+1; 
        flag[i]=1;
     }
   }
}

if(cnt!=v)
{
  printf("Cycles exist no topological sorting possible\n");
 //printf("abhishek");
}
else
{

  printf("The topological sorting is\n"); 
  for(int i=0;i<v;i++)
   printf("%c\t",s[i]+65);
  
}
}

void main()
{
  int v;
  printf("Enter number of vertices\n"); scanf("%d",&v);
  int *arr[v];
  for(int i=0;i<v;i++)
  arr[i]=(int *)malloc(sizeof(int)*v); 
printf("Enter the adjacency matrix\n");

  for(int i=0;i<v;i++)
{
  //printf("Enter 1 for the vertices adjacent to vertex %c\n",i+65); 
   for(int j=0;j<v;j++)
  {
    //printf("\nVertex %c : ",j+65);
     scanf("%d",&arr[i][j]);
  }
}
printf("\n");

     printf("Adjacency matrix\n"); 
   for(int i=0;i<v;i++)
  {
    for(int j=0;j<v;j++)
    {
     printf("%d\t",arr[i][j]);
    }
     printf("\n");
   }
printf("\n");
  QUE q;
  q.f=0;
  q.r=-1;
  q.cnt=0;
   q.arr=(int*)malloc(sizeof(int)*v);

  int *inq=(int *)malloc(sizeof(int)*v);
   for(int i=0;i<v;i++)
   inq[i]=0;
 int *flag=(int *)malloc(sizeof(int)*v); 
 for(int i=0;i<v;i++)
 flag[i]=0; 
 
   indegree(arr,v,inq,&q,flag);
   sourceremove(arr,v,&q,inq,flag);

printf("\n");
}
