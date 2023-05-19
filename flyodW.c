#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int matrix[MAX][MAX],n;
void floydwarshal()
{
int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(matrix[i][k]+matrix[k][j]<matrix[i][j])
                {
                    matrix[i][j]=matrix[i][k]+matrix[k][j];
                } 
            }
        }
 }
    printf("\nShortest path matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]==999)
                printf("%s\t","INF");
            else
                printf("%d\t",matrix[i][j]);
        }
           printf("\n");
    }
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
        floydwarshal();
}