//Binary search tree insertion and display in-order without using recursion
#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
typedef struct tree tree;
struct stack
{
    tree *address;
    struct stack *next;
};
typedef struct stack stack;
tree *root = NULL;
stack *top = NULL;
void push(tree *node)
{
    stack *t = (stack *)malloc(sizeof(stack));
    t->address = node;
    t->next = top;
    top = t;
}
tree *pop()
{
    tree *t = NULL;
    if (top != NULL)
    {
        t = top->address;
        top = top->next;
    }
    return t;
}
void insert(int e)
{
    tree *t = (tree *)malloc(sizeof(tree));
    t->data = e;
    t->left = NULL;
    t->right = NULL;
    if (root == NULL)
        root = t;
    else
    {
        tree *p = NULL, *x = root;
        while (x != NULL)
        {
            p = x;
            if (e == x->data)
            {
                printf("Duplication not allowed\n");
                return;
            }
            x = e > x->data ? x->right : x->left;
        }
        if (e > p->data)
            p->right = t;
        else
            p->left = t;
    }
}
void inorderwr()
{
    tree *t = root;
    while (t != NULL)
    {
        push(t);
        t = t->left;
    }
    t = pop();
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->right;
        while (t != NULL)
        {
            push(t);
            t = t->left;
        }
        t = pop();
    }
}
int main()
{
    int ch,n;
    printf("ENTER THE SIZE:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter Element To Insert: ");
            scanf("%d", &ch);
            insert(ch);
    }
    printf("Inorder Without Using Recussion: ");
    inorderwr();
    return 0;
}

