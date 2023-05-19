#include<stdio.h>
#include<stdlib.h>
int nE,nV,in[10]={0},out[10]={0},tot[10]={0};
struct node
{
	int vertex;
	struct node *next;
}*head[10]={NULL},*temp,*last;
void creategraph();
void displaygraph();
void append();
void BFS();
void DFS();
void main()
{
	creategraph();
	displaygraph();
	BFS();
	DFS();
}
void creategraph()
{
	int i,j,ch;
	printf("Enter number of vertices and edges:");
	scanf("%d %d",&nV,&nE);
	for(i=0;i<nV;i++)
		for(j=0;j<nE;j++)			
		{
			printf("Is there any edge(%d,%d)(Y/N)",i+1,j+1);
			ch=getchar();
			ch=getchar();
			if(ch=='Y')
				append(i,j);
		}
}
void append(int x,int y)
{
	temp=(struct node *)malloc(sizeof(struct node));
	temp->vertex=y;
	temp->next=NULL;
	if(head[x]==NULL)
		head[x]=temp;
	else
	{
		for(last=head[x];last->next!=NULL;last=last->next);
		last->next=temp;
	}

}
void displaygraph()
{
	int i,j;
	printf("\n Vertex \t Adajacent vertex");
	for(i=0;i<nV;i++)
	{
		printf("\n(%d)\t",i+1);
		for(temp=head[i];temp!=NULL;temp=temp->next)
			printf("\t %d",temp->vertex+1);
	}
}
void BFS()
{
	int visited[10]={0},q[10]={-1},qcnt=0,i,j,selvertex,start;
label1:printf("\n Enter start vertex");
       scanf("%d",&start);
       if(start<0 || start>nV)
       {
	       printf("Enter Valid vertex");
	       goto label1;
       }
       q[qcnt++]=start;
       i=0;
       printf("\n Vertex \t Spanning tree");
       while(i!=qcnt)
       {
	       selvertex=q[i++];
	       visited[selvertex]=1;
	       printf("\n [%d]",selvertex+1);
	       for(temp=head[selvertex];temp!=NULL;temp=temp->next)
	       {
		       if(visited[temp->vertex]==0)
		       {
			       q[qcnt++]=temp->vertex;
			       visited[temp->vertex]=1;
			       printf("\t %d %d",selvertex+1,temp->vertex+1);
		       }
	       }
       }
}
void DFS()
{
	int visited[10]={0},stack[10]={-1},scnt=0,i,j,t_array[10],selvertex,start,cnt;
label1:printf("\n Enter start vertex:");
       scanf("%d",&start);
       if(start<0 || start>nV)
       {
	       printf("Enter valid start vertex");
	       goto label1;
       }
       stack[scnt++]=start;
       while(scnt!=0)
       {
	       selvertex=stack[scnt-1];
	       visited[selvertex]=1;
	       printf("\n [%d]",selvertex+1);
	       cnt=0;
	       i=0;
	       for(temp=head[selvertex];temp!=NULL;temp=temp->next)
		       if(visited[temp->vertex]==0)
		       {
			       cnt++;
			       t_array[i++]=temp->vertex;
		       }
	       if(cnt==0)
		       scnt--;
	       else
	       {
		       for(j=i-1;j>=0;j--)
			       stack[scnt++]=t_array[j];
		       if(scnt>1 && visited[stack[scnt-1]]==0)
			       printf("\t %d %d",selvertex+1,stack[scnt-1]+1);
	       }
       }
}
