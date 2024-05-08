//Binary search tree insertion and display Traversal using inorder, preorder and postorder using recursion.

#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node* left;
        struct node* right;
};
struct node*root=NULL;
void insert(int e)
{
        struct node*p;
         struct node*x;
        if(root==NULL)
        {
                root=(struct node*)malloc(sizeof(struct node));
                root->data=e;
                root->left=NULL;
                root->right=NULL;
        }
        else
        { p=root;
            while(p!=NULL)
            {   x=p;
                if(p->data>e)
                {
                    p=p->left;
                }
                else
                {
                    p=p->right;
                }
            }
            if(x->data>e)
            {
                x->left=(struct node*)malloc(sizeof(struct node));
                x->left->data=e;
                x->left->left=NULL;
                x->left->right=NULL;
            }
            else 
            {
                    x->right=(struct node*)malloc(sizeof(struct node));
                    x->right->data=e;
                    x->right->left=NULL;
                    x->right->right=NULL;    
            }
        }
}
void inorder(struct node*r)
{
        if(r!=NULL)
        {
                inorder(r->left);
                printf("%d\t",r->data);
                inorder(r->right);
        }
}
void preorder(struct node*r)
{
        if(r!=NULL)
        {
                printf("%d\t",r->data);
                inorder(r->left);
                inorder(r->right);
        }
}
void postorder(struct node*r)
{
        if(r!=NULL)
        {
                inorder(r->left);
                inorder(r->right);
                printf("%d\t",r->data);
        }
}
int main()
{
    int ch,n;
    printf("\nMENU");
    printf("\n1.INSERT");
    printf("\n2.IN-ORDER");
    printf("\n3.PRE-ORDER");
    printf("\n4.POST-ORDER");
    printf("\n3.EXIT");
    do{    
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nenter the element to the tree:");
                    scanf("%d",&n);
                    insert(n);
                    break;
            case 2:printf("\nIN-ORDER\n");
                    inorder(root);
                    break;
            case 3:printf("\nPRE-ORDER\n");
                    preorder(root);
                    break;
            case 4:printf("\nPOST-ORDER\n");
                    postorder(root);
                    break;
            case 5:printf("**EXIT**");
                    break;
            default:printf("\nwrong choice");
                    break;
        }
                
    }while(ch!=5);
}
