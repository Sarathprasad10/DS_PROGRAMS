/* Write a program with functions  to insert a new node 
a.	at the beginning of a Singly Linked List.
b.	At the end of the linked list
c.	after a specified element in a linked list. */
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insertAtBeginning(int e) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = e;
    newNode->next = head;
    head = newNode;
    printf("\n%d inserted at the beginning of the list", e);
}

void insertAtEnd(int e) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = e;
    newNode->next = NULL;

    if (head == NULL) 
    {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("\n%d inserted at the end of the list", e);
}

void insertAfterElement(int target, int e) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = e;
    newNode->next = NULL;

    struct node *temp = head;
    while (temp != NULL && temp->data != target) 
    {
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("%d not found in the list. Cannot insert.\n", target);
        free(newNode);
    } else 
    {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("\n%d inserted after %d in the list", e, target);
    }
}
void display() 
{
    struct node *t = head;
    printf("\nThe elements are:\n");
    while (t != NULL) 
    {
        printf("%d\t", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() 
{
    int ch, n, target;
    printf("\tMENU");
    printf("\n**************************");
    printf("\n*  1.Insert At Beginning *");
    printf("\n*  2.Insert At End       *");
    printf("\n*  3.Insert After Element*");
    printf("\n*  4.DISPLAY             *");
    printf("\n*  5.Exit                *");
    printf("\n**************************");
     do {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                printf("\nEnter the number to insert at the beginning:");
                scanf("%d", &n);
                insertAtBeginning(n);
                break;
            case 2:
                printf("\nEnter the number to insert at the end:");
                scanf("%d", &n);
                insertAtEnd(n);
                break;
            case 3:
                printf("\nEnter the element after which to insert:");
                scanf("%d", &target);
                printf("\nEnter the number to insert:");
                scanf("%d", &n);
                insertAfterElement(target, n);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\n**EXIT**\n");
                break;
            default:
                printf("WRONG CHOICE\n");
                break;
        }
    } while (ch != 5);
    struct node *temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
