#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
int graph[MAX_NODES][MAX_NODES];
int inDegree[MAX_NODES];
int n; 
void topologicalSort()
{
    int queue[MAX_NODES];
    int front = -1, rear = -1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
         {
            if (graph[i][j] == 1) 
            {
                inDegree[j]++;
            }
        }               
    }
     for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0) 
        {
            queue[++rear] = i;
        }
    }   
    while (front != rear)
    {
        int node = queue[++front];
        printf("%d ", node);
        count++;
        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1)
            {
                if (--inDegree[i] == 0)
                {
                    queue[++rear] = i;
                }
            }
         }
    }
    if (count != n) 
    {
        printf("Graph has a cycle\n");
    }
}
