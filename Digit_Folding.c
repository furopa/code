#include<stdio.h>
#include<stdlib.h>
void init();
void insert();
void display();
void search();
void delete();
int ht[10];
void main()
{
	int n;
	while(1)
	{
		printf("\n++++MENU++++");
		printf("\n 1:init \n 2:insert \n 3:display \n 4:search \n 5:delete \n 6:exit");
		printf("\n enter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:init();
			       break;
			case 2:insert();
			       break;
			case 3:display();
			       break;
			case 4:search();
			       break;
			case 5:delete();
			       break;
			case 6:exit(0);
			default:printf("INVALID CHOICE!!");
				exit(0);
		}
	}
}

void init()
{
	int i;
	for(i=0;i<=10;i++)
		ht[i]=-1;
}

void insert()
{
	int n,b,i,s,n1,d;
	printf("\n enter element to insert \n ");
	scanf("%d",&n);
	n1=n;
	while(n1>9)
	{
		s=0;
		while(n1>0)
		{
		d=n1%10;
		s=s+d;
		n1=n1/10;
		}
		n1=s;
		}
		b=n1;
		if(ht[b]==-1)
		{
		ht[b]=n;
		printf("\n element %d inserted in %d bucket",n,b);
		return;
	}
	else
		if(b==9)
			b=-1;
	for(i=b+1;i!=b;i=(i+1)%10)
	{
		if(ht[i]==-1)
		{
			ht[i]=n;
			printf("\n element %d inserted in %d bucket",n,i);
			return;
		}
	}
	printf("\n hash table is full");
}


void display()
{
	int i;
	printf("\n hash table");
	for(i=0;i<10;i++)
	{
		if(ht[i]==-1)
		{
			printf("\n bucket %d=!Empty!",i);
		}
		else
		{
			printf("\n Bucket %d=%d",i,ht[i]);
		}
	}
}

void search()
{
	int n,b,i,n1,s,d;
	printf("\n enter element to search:");
	scanf("%d",&n);
	n1=n;
	while(n1>9)
	{
	s=0;
	while(n1>0)
	{
	d=n1%10;
	s=s+d;
	n1=n1/10;
	}
	n1=s;
	}
	b=n1;
	if(ht[b]==n)
	{
	printf("\n element %d found at %d Bucket ",n,b);
	return;
	}
        else
	{
		if(b==9)
			b=-1;
		for(i=b+1;i!=b;i=(i+1)%10)
		{
			if(ht[i]==n)
			{
				printf("\n Element %d found at %d Bucket",n,i);
				return;
			}
		}
	}
	printf("\n Element not found \n");
}

void delete()
{
	int n,b,i,n1,s,d;
	printf("\n enter element to delete:");
	scanf("%d",&n);
	n1=n;
	while(n1>9)
	{
		s=0;
		while(n1>0)
		{
		d=n1%10;
		s=s+d;
		n1=n1/10;
		}
		n1=s;
		}
		b=n1;
		if(ht[b]==n)
		{
		    ht[b]=-1;
		    printf("\n element %d deleted from %d bucket",n,b);
		    return;
		}
		else
         	{
		if(b==9)
			b=-1;
		for(i=b+1;i!=b;i=(i+1)%10)
		{
			if(ht[i]==n)
			{
				ht[i]=-1;
				printf("\n element %d deleted from %d Bucket",n,i);
				return;
			}
		}
	}
	printf("\n Element not found in hash table ");
}


