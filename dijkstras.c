#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int n,source;
int matrix[MAX][MAX];
void dijkstra(int vertex)
{
    int i,j,u,v,count,min;
    int dist[MAX],visited[MAX]={0};
    visited[vertex]=1;
    for(i=0;i<n;i++)
        dist[i]=matrix[vertex][i];
    count=2;
    while(count<n)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            if(visited[i]==0 && dist[i]<min)
            {
                min=dist[i];
                u=i;
            }
        }
        visited[u]=1;
        for(v=0;v<n;v++)
        {
            if(dist[u]+matrix[u][v]<dist[v])
                dist[v]=dist[u]+matrix[u][v];
        }
        count++; 
    }
    printf("\nVertex\tDistance from source:\n");
    for(i=0;i<n;i++)
        printf("%d\t\t%d\n",i,dist[i]);
}
void main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        scanf("%d", &matrix[i][j]);
    }
    printf("\nEnter the source vertex: ");
    scanf("%d", &source);
    dijkstra(source);
}