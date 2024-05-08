//Binary search tree insertion using names and display the names in ascending order using inorder traversal.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tree
{
    char name[50];
    struct tree *left;
    struct tree *right;
};
typedef struct tree tree;
void insert(tree **root, const char *name)
{
    if (*root == NULL)
    {
        *root = (tree *)malloc(sizeof(tree));
        strcpy((*root)->name, name);
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else
    {
        int compareResult = strcmp(name, (*root)->name);
        if (compareResult < 0)
        {
            insert(&((*root)->left), name);
        }
        else if (compareResult > 0)
        {
            insert(&((*root)->right), name);
        }
    }
}

void inorderTraversal(tree *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%s\n", root->name);
        inorderTraversal(root->right);
    }
}

int main()
{
    int n;
    char name[50];
    tree *root = NULL;
    printf("Enter the number of names: ");
    scanf("%d", &n);

    printf("Enter the names: ");
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", name);
        insert(&root, name);
    }
    printf("Names in ascending order:\n");
    inorderTraversal(root);
    return 0;
}
