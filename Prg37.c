/* Write a program with functions to delete a node
a.	From the beginning of the linked list
b.	From the end of the linked list
c.	The node with specified data element */
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
    struct node *t;
    if (head == NULL)
    {
        head = (struct node*)malloc(sizeof(struct node));
        head->data = e;
        head->next = NULL;
    } else 
    {
        t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = (struct node*)malloc(sizeof(struct node));
        t->next->data = e;
        t->next->next = NULL;
    }
}
void deleteFromBeginning() 
{
    if (head == NULL) 
    {
        printf("\nNo elements to delete");
    } else {
        struct node *temp = head;
        head = head->next;
        free(temp);
        printf("\nNode deleted from the beginning of the list");
    }
}
void deleteFromEnd()
{
    if (head == NULL) 
    {
        printf("\nNo elements to delete");
    } else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("\nNode deleted from the end of the list");
    } else {
        struct node *temp = head;
        while (temp->next->next != NULL) 
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        printf("\nNode deleted from the end of the list");
    }
}
void deleteNodeWithElement(int e) 
{
    struct node *temp = head, *prev = NULL;
    if (head == NULL) {
        printf("\nNo elements to delete");
        return;
    }
    if (temp->data == e) 
    {
        head = head->next;
        free(temp);
        printf("\nNode with data %d deleted", e);
        return;
    }
    while (temp != NULL && temp->data != e) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nElement not found in the list");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("\nNode with data %d deleted", e);
    }
}
void display() 
{
    struct node *t = head;
    if (head == NULL) {
        printf("\nNo elements to display");
    } else {
        printf("\nThe elements are:\n");
        while (t != NULL) {
            printf("%d\t", t->data);
            t = t->next;
        }
        printf("\n");
    }
}
int main() 
{
    int ch, n;
    printf("\tMENU");
    printf("\n*******************************");
    printf("\n*  1.INSERT                   *");
    printf("\n*  2.DELETE FROM BEGINNING    *");
    printf("\n*  3.DELETE FROM END          *");
    printf("\n*  4.DELETE NODE WITH ELEMENT *");
    printf("\n*  5.DISPLAY                  *");
    printf("\n*  6.Exit                     *");
    printf("\n*******************************");

    do {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch) 
        {
            case 1: printf("\nEnter the number:");
                        scanf("%d",&n);
                        insert(n);
                        break;
            case 2:deleteFromBeginning();
                break;
            case 3:deleteFromEnd();
                break;
            case 4:printf("\nEnter the element to delete:");
                scanf("%d", &n);
                deleteNodeWithElement(n);
                break;
            case 5:display();
                break;
            case 6:printf("\n**EXIT**");
                break;
            default:
                printf("WRONG CHOICE");
                break;
        }
    } while(ch != 6);
    struct node *temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

