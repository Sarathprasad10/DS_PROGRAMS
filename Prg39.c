//Sort the elements in a linked list using changing the values (swapping the values)

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
void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void sortLinkedList()
{
    struct node *i, *j;
    int swapped;
    for (i = head; i != NULL; i = i->next)
    {
        swapped = 0;
        for (j = head; j != NULL; j = j->next)
        {
            if (j->next != NULL && j->data > j->next->data)
            {
                swap(j, j->next);
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
    struct node *t;
    if (head == NULL)
    {
        printf("\nNo elements");
    }
    else
    {
        printf("\nLinked list sorted successfully!\n");
        t = head;
        while (t != NULL)
        {
            printf("%d\t", t->data);
            t = t->next;
        }
    }
}
int main()
{
    int ch, n;
    printf("\tMENU");
    printf("\n*********************");
    printf("\n*  1.INSERT         *");
    printf("\n*  2.DISPLAY        *");
    printf("\n*  3.SORT & DISPLAY *");
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
            sortLinkedList();
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

