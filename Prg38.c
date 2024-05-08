//Write a program to create a singly linked list of n nodes and display it in reverse order.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int e)
{
    struct node *t;
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = e;
        head->next = NULL;
    }
    else
    {
        t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = (struct node *)malloc(sizeof(struct node));
        t->next->data = e;
        t->next->next = NULL;
    }
}

void display()
{
    struct node *t;
    if (head == NULL)
    {
        printf("\nNo elements");
    }
    else
    {
        printf("\nThe elements are:\n");
        t = head;
        while (t != NULL)
        {
            printf("%d\t", t->data);
            t = t->next;
        }
    }
}

void reverseAndDisplay(struct node *p)
{
    if (p == NULL)
    {
        return;
    }
    reverseAndDisplay(p->next);
    printf("%d\t", p->data);
}

int main()
{
    int ch, n;
    printf("\tMENU");
    printf("\n*********************");
    printf("\n*  1.INSERT         *");
    printf("\n*  2.DISPLAY        *");
    printf("\n*  3.DISPLAY REVERSE*");
    printf("\n*  4.EXIT           *");
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
            display();
            break;
        case 3:
            printf("\nThe elements in reverse order are:\n");
            reverseAndDisplay(head);
            printf("\n");
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

