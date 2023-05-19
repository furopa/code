#include<stdio.h>
#include<stdlib.h>
typedef struct tnode
{
    struct tnode *prev;
    int info;
    struct tnode *next;
}TNODE;

TNODE *insert(TNODE *root,int item)
{
    if(root==NULL)
    {
        root=(TNODE*)malloc(sizeof(TNODE));
        root->info=item;
        root->prev=root->next=NULL;
        return root;
    }
    if(root->info<item)
        root->next=insert(root->next,item);
    if(root->info>item)
        root->prev=insert(root->prev,item);
    return root;
}
void inorder(TNODE *root)
{
    if(root!=NULL)
    {
        inorder(root->prev);
        printf("%d\t",root->info);
        inorder(root->next);
    }
}
TNODE *treecopy(TNODE *root)
{
    TNODE *newnode;
    if(root==NULL)
        return NULL;
    else
    {
        newnode=(TNODE*)malloc(sizeof(TNODE));
        newnode->info=root->info;
        newnode->prev=treecopy(root->prev);
        newnode->next=treecopy(root->next);
        return newnode;
    }
}
int comparebst(TNODE *root1,TNODE *root2)
{
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1->info==root2->info)
    {
        if(comparebst(root1->prev,root2->prev))
            return (comparebst(root1->next,root2->next));
    }
    return 0;
}
void main()
{
    int n,item,i,flag;
    TNODE *root1=NULL,*root2=NULL,*root3=NULL;

    printf("\nEnter number of nodes of 1st tree: ");
    scanf("%d",&n);
    printf("Enter the nodes of 1st tree:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        root1=insert(root1,item);
    }

    printf("\nEnter number of nodes of 2nd tree: ");
    scanf("%d",&n);
    printf("Enter the nodes of 2nd tree:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        root2=insert(root2,item);
    }
    printf("\nInorder traversal of 1st tree:\n");
    inorder(root1);
    printf("\nInorder traversal of 2nd tree:\n");
    inorder(root2);

    flag=comparebst(root1,root2);
    if(flag==1)
        printf("\n\nBoth BST are same.\n");
    else
        printf("\n\nBoth BST are not same.\n");

    root3=treecopy(root1);
    printf("\nCopy of 1st tree created in 3rd tree.\n");
    inorder(root3);
}
