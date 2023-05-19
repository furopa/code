#include<stdio.h>
#include<stdlib.h>
struct node
{
    int vertex;
    struct node *next;
}*head[10],*newnode;
int ne,nv;
int in[10],out[10],total[10];
void accept();
void display();
void calculatedegree();
void init();
void append(int,int);
void main()
{
    init();
    accept();
    display();
    calculatedegree();
}
void init()
{
    int i;
    for(i=0;i<10;i++)
        head[i]=NULL;
}
void accept()
{
int i,j;
     char ch;
     printf("Enter number of Vertices: ");
     scanf("%d",&nv);
     printf("Enter number of Edges: ");
     scanf("%d",&ne);
    for(i=0;i<nv;i++)
        for(j=0;j<nv;j++)
        {
            printf("Is there any edge (%d,%d) (y/n)? ",i+1,j+1);
            ch=getchar();
            ch=getchar();
            if(ch=='y'|| ch=='Y')
                append(i,j);
        }
}
void append(int x,int y)
{
    struct node *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->vertex=y;
    newnode->next=NULL;
    if(head[x]==NULL)
     head[x]=newnode;
    else
    {
        for(temp=head[x];temp->next!=NULL;temp=temp->next);
    }
}
void display()
{
    struct node *temp;
    int i;
    printf("\n\nVertex\tAdjacent vertices\n");
    for(i=0;i<nv;i++)
    {
        printf("\n[%d]\t",i+1);
        for(temp=head[i];temp!=NULL;temp=temp->next)
            printf("-> %d",temp->vertex+1);
    } 
}
void calculatedegree()
{
    struct node *temp;
    int i,j;
    for(i=0;i<nv;i++)
    {
        for(temp=head[i];temp!=NULL;temp=temp->next)
        {
            out[i]++;
            j=temp->vertex;
            in[j]++; 
        }
    }
    printf("\n\n\nVertex\tIndegree\tOutdegree\tTotal\n");
    for(i=0;i<nv;i++)
    {
        total[i]=in[i]+out[i];
        printf("\n[%d]\t\t%d\t\t%d\t\t%d",i+1,in[i],out[i],total[i]);
    }
}