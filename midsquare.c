#include<stdio.h>
#include<stdlib.h>
void init();
void insert();
void display();
void delete();
void search();
int ht[10];
void main()
{
	 int n;
         while(1)
	 {
		  printf("\n MENU \n");
                  printf("\n1.Init \n2.Insert \n3.Display \n4.Del \n5.Search \n6.Exit \n");
                  printf("\n Enter your Choice ");
                  scanf("%d",&n);
		 switch(n)
		 {
			 case 1:init();
				 break;
			 case 2:insert();
				 break;
			 case 3:display();
				 break;
			 case 4:delete();
				 break;
			 case 5:search();
				 break;
			 case 6:exit(0);
			 default:printf("\n Invalid \n");
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
	 int n,b,i,s,r,len=0,posn,s1;
	 printf("\n Enter Element to insert \n");
	 scanf("%d",&n);
	 s=n*n;
	 printf("\nsquare=%d",s);
	 s1=s;
	 while(s!=0)
	 {
	 	// r=s%10;
		 len++;
		 s=s/10;
	 }
	 printf("\nlen=%d",len);
	 //if(len==2)
	 //{
		//posn=0;
		 //s1=0;
	 // }
	// else
	{
		 if(len%2==0)
		 posn=(len/2);
		 else
		 posn=(len/2)+1;
	 }
	 printf("\nposn=%d",posn);
	 for(i=1;i<posn;i++)
	 {
		 s1=s1/10;
	 }
	 printf("\ns1=%d",s1);
	 if(len==2)
	 b=0;
	 else
	 b=s1%10;
	 printf("\nb=%d",b);
	
	 if(ht[b]==-1)
	 {
		 ht[b]=n;
		 printf("\n Element %d inserted in %d Bucket",n,b);
		 return;
	 }
	 else
	 {
		 if(b==9)
		 b=-1;
		 for(i=b+1;i!=b;i=(i+1)%10)
		 {
			 if(ht[i]==-1)
			 {
				 ht[i]=n;
				 printf("\n Element %d inserted in %d Bucket",n,i);
				 return;
			 }
		 }
	 }
	 printf("\n Hash Table is full \n");
 }

 void display()
 {
	 int i;
	 printf("\n Hash Table \n");
	 for(i=0;i<10;i++)
	 {
		 if(ht[i]==-1)
		 {
			 printf("\n Bucket %d = Empty",i);
		 }
		 else
		 {
			 printf("\n Bucket %d = %d",i,ht[i]);
		 }
	 }
}
 void delete()
 {
		 int n,b,i,s,r,len=0,posn,s1;
		 printf("\n Enter Element to Delete");
		 scanf("%d",&n);
		 s=n*n;
		 s1=s;
		 while(s!=0)
		 {
			 r=s%10;
			 len++;
			 s=s1/10;
		 }
		 if(len%2==0)
			 posn=len/2;
		 else
			 posn=(len/2)+1;
			 for(i=1;i<posn;i++)
			 {
				 s1=s1/10;
			 }
			 b=s1%10;
			 if(ht[b]==n)
			 {
				 ht[b]=-1;
				 printf("\n Element %d Deleted from %d Bucket",n,b);
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
						 printf("\n Element %d Deleted from %d Bucket",n,i);
						 return;
					 }
				 }
			 }
			 printf("\n Element Not Found in Hash Table");
 }
 void search()
{
	int n,b,i,s,r,len=0,posn,s1;
	 printf("\n Enter Element to search");
	 scanf("%d",&n);
	 s=n*n;
	 s1=s;
	 while(s!=0)
	 {
		 r=s%10;
		 len++;
		 s=s1/10;
	 }
	 if(len%2==0)
		 posn=len/2;
	 else
		 posn=(len/2)+1;
	 for(i=1;i<posn;i++)
	 {
		 s1=s1/10;
	 }
	 b=s1%10;
	 if(ht[b]==n)
	 {
		 printf("\n Element %d Found at %d Bucket",n,b);
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
				 printf("\n Element %d Found at %d Bucket",n,i);
				 return;
			 }
		 }
	 }
	 printf("\n Element Not Found \n");
 }
