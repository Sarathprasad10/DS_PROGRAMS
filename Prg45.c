//Perform the respective operations on the following:Circular Linked List

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insert(int e)
{ 
    struct node *t, *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = e;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        head->next = head; 
    }
    else
    { 
        t = head;
        while(t->next != head)
        {
            t = t->next;
        }
        t->next = newNode;
        newNode->next = head; 
    }
}
void deleteNode(int key)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct node *current = head, *prev = NULL;
    if (current->data == key)
    {
        while (current->next != head)
        {
            current = current->next;
        }
        if (current == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            current->next = head->next;
            free(head);
            head = current->next;
        }
        printf("Node with data %d deleted successfully.\n", key);
        return;
    }
    while (current->next != head && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == head)
    {
        printf("Node with data %d not found in the list.\n", key);
        return;
    }
    prev->next = current->next;
    printf("Node with data %d deleted successfully.\n", key);
}
void display()
{
    struct node *t;
    if (head == NULL)
    {
        printf("\nno elements");
    }
    else
    {       
        printf("\nThe elements are:\n");
        t = head;
        do
        {
            printf("%d\t", t->data);
            t = t->next;
        } while(t != head);
        printf("\n");
    }
}
int main()
{
    int ch, n;
    printf("\tMENU");
    printf("\n*********************");
    printf("\n*  1.INSERT         *");
    printf("\n*  2.DELETE         *");
    printf("\n*  3.DISPLAY        *");
    printf("\n*  4.Exit           *");
    printf("\n*********************");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\nEnter the number:");
                    scanf("%d", &n);
                    insert(n);
                    break;
            case 2: printf("\nEnter the number to delete:");
                    scanf("%d", &n);
                    deleteNode(n);
                    break;
            case 3: display();
                    break;
            case 4: printf("\n**EXIT**");
                    break;
            default: printf("WRONG CHOICE");
                    break;
        }
    } while(ch != 4);
    return 0;
}

