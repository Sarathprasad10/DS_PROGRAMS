//Sort the elements in a linked list using Changing the address (Swapping the address)
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head = NULL;
void insert()
{
    int e;
    printf("Enter the element to be inserted:");
    scanf("%d", &e);
    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->data = e;
        head->next = NULL;
    }
    else
    {
        node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = (node *)malloc(sizeof(node));
        t->next->data = e;
        t->next->next = NULL;
    }
}
void disp()
{
    if (head == NULL)
    {
        printf("Empty linked list.\n");
    }
    else
    {
        node *t = head;
        while (t != NULL)
        {
            printf("%d\t", t->data);
            t = t->next;
        }
        printf("\n");
    }
}
void sort_add()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
    }
    else if (head->next == NULL)
    {
        printf("\nOnly one element in the list... Enter more elements.\n");
    }
    else
    {
        node *i = NULL;
        node *j = NULL;
        node *k = NULL;
        node *t1, *t2;
        for (i = head; i != NULL; i = i->next)
        {
            k = head;
            for (j = k->next; j->next != NULL; j = j->next, k = k->next)
            {

                if (j->data >= j->next->data)
                {
                    t1 = j;
                    t2 = j->next->next;
                    j = j->next;
                    j->next = t1;
                    j->next->next = t2;
                    k->next = j;
                }
            }
            if (head->data >= head->next->data)
            {
                t1 = head;
                t2 = head->next->next;
                head = head->next;
                head->next = t1;
                head->next->next = t2;
            }
        }
        printf("\nSorted :-\n");
        disp();
    }
}
int main()
{
    int ch;
     printf("\tMENU");
    printf("\n*********************");
    printf("\n*  1.INSERT         *");
    printf("\n*  2.DISPLAY        *");
    printf("\n*  3.SORT           *");
    printf("\n*  4.Exit           *");
    printf("\n*********************");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:insert();
            break;
        case 2:disp();
            break;
        case 3:sort_add();
            break;
        case 4:printf("\n**EXIT**");
            break;
        default:
            printf("Enter a valid choice !");
            break;
        }
    } while (ch != 4);
    return 0;
}

