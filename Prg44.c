//Perform the respective operations on the following:Linked Queue 
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* f = NULL;
struct node* r = NULL; 
void enqueue(int e)
{
    struct node* t;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = e;
    t->next = NULL;
    if (f == NULL)
    {
        f = t;
        r = t;
    }
    else
    {
        r->next = t;
        r = t;
    }
}
void dequeue()
{
    struct node* t;
    if (f == NULL)
    {
        printf("\nThe queue is empty");
    }
    else
    {
        t = f;
        printf("\n%d is dequeued", t->data);
        f = f->next;
        if (f == NULL)
        {
            r = NULL; 
        }
    }
}
void display()
{
    if (r == NULL && f == NULL)
    {
        printf("\nNO ELEMENTS");
    }
    else
    {
        struct node* t;
        t = f;
        while (t != NULL)
        {
            printf("\t%d", t->data);
            t = t->next;
        }
    }
}
int main()
{
    int ch, n;
    printf("\nMENU");
    printf("\n1.ENQUEUE");
    printf("\n2.DISPLAY");
    printf("\n3.DEQUEUE");
    printf("\n4.EXIT");
    do
    {
        printf("\nENTER YOUR CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter the element to enqueue:");
                scanf("%d", &n);
                enqueue(n);
                break;
            case 2:
                printf("\nDISPLAY\n");
                display();
                break;
            case 3:
                printf("\nDEQUEUE");
                dequeue();
                break;
            case 4:
                printf("\n**EXIT**");
                break;
            default:
                printf("\nWrong choice");
                break;
        }
    } while (ch != 4);
    return 0;
}

