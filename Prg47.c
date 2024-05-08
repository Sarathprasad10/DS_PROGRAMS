//Perform the respective operations on the following:Circular doubly linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
void insert(int e)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = e;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        struct node *lastNode = head->prev;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = head;
        head->prev = newNode;
    }
}
void delete(int e)
{
    struct node *temp = head;
    do
    {
        if (temp->data == e)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == head)
            {
                if (temp->next == head)
                {
                    head = NULL;
                }
                else
                {
                    head = temp->next;
                }
            }
            printf("\n%d is deleted", e);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("\nElement not found");
}
void display()
{
    if (head == NULL)
    {
        printf("\nThe list is empty\n");
        return;
    }
    printf("\nThe elements are:\n");
    struct node *temp = head;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != head);
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
        switch (ch)
        {
        case 1:
            printf("\nEnter the number:");
            scanf("%d", &n);
            insert(n);
            break;
        case 2:
            printf("\nEnter the number to delete:");
            scanf("%d", &n);
            delete(n);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n**EXIT**");
            break;
        default:
            printf("WRONG CHOICE");
            break;
        }
    } while (ch != 4);

    return 0;
}

