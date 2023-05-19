#include<stdio.h>
#include<stdlib.h>
int matrix[10][10],in[10],out[10],total[10];
int nV,nE;
void accept();
void display();
void calculateDeg();
void displayDeg();
void main()
{
    accept();
     display();
     calculateDeg();
     displayDeg();
}
void accept()
{
     char ch;
     int i,j;
     printf("Enter number of Vertices: ");
     scanf("%d",&nV);
     printf("Enter number of Edges: ");
     scanf("%d",&nE);
     for(i=0;i<nV;i++)
          for(j=0;j<nV;j++)
          {
            printf("Is there an edge present between (%d,%d) (Y/N):",i+1,j+1);
            ch=getchar();
            ch=getchar();
            if(ch=='Y'||ch=='y')
            matrix[i][j]=1;
          }
}
void display()
{ 
    printf("\n\nThe matrix is:\n");
    for(i=0;i<nV;i++)
    printf("\t(%d)",i+1);
        for(i=0;i<nV;i++)
        {   
            printf("\n(%d)",i+1);
            for(j=0;j<nV;j++)
            {
                printf("\t%d",matrix[i][j]);
            }
         }
}
void calculateDeg()
{
int i,j;
     for(i=0;i<nV;i++)
          for(j=0;j<nV;j++)
          {
               if(matrix[i][j])
               out[i]++;
               if(matrix[j][i])
               in[i]++;
               total[i]=out[i]+in[i];
          }
}
void displayDeg()
{
int i;
     printf("\n\n\n");
     printf("\tIndegree\tOutdegree\tTotal Degree\n");
     for(i=0;i<nV;i++)
     {
          printf("(%d)\t\t%d\t\t%d\t\t%d\n",i+1,in[i],out[i],total[i]);
     }
}