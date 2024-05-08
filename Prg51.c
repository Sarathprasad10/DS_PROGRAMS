//Binary search tree insertion and display post-order without using recursion
#include <stdio.h>
#include <stdlib.h>
struct TreeNode 
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;
struct StackNode 
{
    TreeNode* node;
    struct StackNode* next;
};
typedef struct StackNode StackNode;
StackNode* stack = NULL;
void push(TreeNode* node)
{
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->node = node;
    new_node->next = stack;
    stack = new_node;
}
TreeNode* pop() 
{
    if (stack == NULL) 
    {
        return NULL;
    }
    TreeNode* node = stack->node;
    StackNode* temp = stack;
    stack = stack->next;
    free(temp);
    return node;
}
void insert(TreeNode** root, int value) 
{
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL) 
    {
        *root = new_node;
    } 
else 
{
        TreeNode* current = *root;
        TreeNode* parent = NULL;
        while (current != NULL) 
        {
            parent = current;
            if (value < current->data) 
            {
                current = current->left;
            } else if (value > current->data) 
            {
                current = current->right;
            } else
            {
            
                return;
            }
        }
        if (value < parent->data)
        {
            parent->left = new_node;
        } else 
        {
            parent->right = new_node;
        }
    }
}
void postOrderIterative(TreeNode* root) 
{
    TreeNode* current = root;
    do {
        while (current != NULL)
        {
            if (current->right != NULL) 
            {
                push(current->right);
            }
            push(current);
            current = current->left;
        }
        current = pop();
        if (current->right != NULL && stack != NULL && current->right == stack->node)
        {
            pop(); 
            push(current);
            current = current->right;
        } else 
        {
            printf("%d ", current->data);
            current = NULL;
        }
    } while (stack != NULL);
}
int main() 
{
    TreeNode* root = NULL;
    int size, value;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    for (int i = 0; i < size; ++i) 
    {
        scanf("%d", &value);
        insert(&root, value);
    }
    printf("Post-order traversal without recursion: ");
    postOrderIterative(root);
    while (stack != NULL) 
    {
        pop();
    }
    return 0;
}
