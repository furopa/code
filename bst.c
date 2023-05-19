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
void preorder(TNODE *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->info);
        preorder(root->prev);
        preorder(root->next);
    } 
}
void postorder(TNODE *root)
{
    if(root!=NULL)
    {
        postorder(root->prev);
        postorder(root->next);
        printf("%d\t",root->info);
    } 
}
int no_levels(TNODE *root)
{
    int left=0,right=0;
    if(root==NULL)
        return 0;
    left=no_levels(root->prev);
    right=no_levels(root->next);
    return (left>right? 1+left:1+right);
}
int countleaf(TNODE *root)
{
    if(root==NULL)
        return 0;
    if((!root->prev)&&(!root->next))
        return 1;
    else
        return (countleaf(root->prev)+countleaf(root->next));
}
int search(TNODE *root,int sno)
{
    if(root==NULL)
        return 0;
    if(sno< root->info)
        search(root->prev,sno);
    else if(sno> root->info)
        search(root->next,sno);
    else
        return 1;
}
int countnodes(TNODE *root)
{
    if(root==NULL)
        return 0;
    return (1+countnodes(root->prev)+countnodes(root->next));
}
int max(TNODE *root)
{
    if(root==NULL)
    return=-1;
    else if(root->next==NULL)
    return root->info;
    else
    {
        return max(root->next);
    }
}
int min(TNODE *root)
{
    if(root==NULL)
    return=-1;
    else if(root->prev==NULL)
    return root->info;
    else
    {
        return min(root->prev);
    }
}
void main()
{
    TNODE *root=NULL;
    int ch,item,sno;
    while(1)
    {
        printf("\nMENU\n1.insert\n2.inorder\n3.preorder\n4.postorder\n5.no. oflevels\n6.no. of leaf nodes\n7.total no. of nodes\n8.search\n9.exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the element: ");
                scanf("%d",&item);
                root=insert(root,item);
                break;
            case 2:
                printf("\nInorder traversal:\n");
                inorder(root);
                break;
            case 3:
                printf("\nPreorder traversal:\n");
                preorder(root);
                break;
            case 4:
                printf("\nPostorder traversal:\n");
                postorder(root);
                break;
            case 5:
                printf("\nNo. of levels= %d\n",no_levels(root));
                                break;
            case 6:
                printf("\nNo. of leaf nodes= %d\n",countleaf(root));
                break;
            case 7:
                printf("\nTotal no. of nodes= %d\n",countnodes(root));
                break;
            case 8:
                printf("\nEnter element to search: ");
                scanf("%d",&sno);
                if(search(root,sno)==0)
                    printf("Search fail.\n");
                else
                    printf("Search successful.\n");
                break;
            case 9: exit(0);
        }
    } 
}