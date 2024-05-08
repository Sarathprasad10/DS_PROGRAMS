//Linked list using names - insert, delete, display, sort, reverse, count
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char *name;
    struct node *next;
};

struct node *head = NULL;

void insert(char *name)
{ 
    struct node *t;
    if(head == NULL)
    {
        head = (struct node*)malloc(sizeof(struct node));
        head->name = strdup(name);
        head->next = NULL;
    }
    else
    { 
        t = head;
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = (struct node*)malloc(sizeof(struct node));
        t->next->name = strdup(name);
        t->next->next = NULL;
    }
}

void delete(char *name)
{
    struct node *t, *prev = NULL;
    if(head == NULL)
    {
        printf("\nno elements");
    }
    else if(strcmp(head->name, name) == 0)
    {
        printf("\n%s is removed", name);
        t = head;
        head = head->next;
        free(t->name);
        free(t);
    }
    else
    {   
        t = head;
        while(t != NULL && strcmp(t->name, name) != 0)
        {
            prev = t;
            t = t->next;
        }
        if(t != NULL)
        {
            printf("\n%s is deleted", name);
            prev->next = t->next;
            free(t->name);
            free(t);
        }
        else
        {
            printf("\n%s not found", name);
        }
    }
}

void display()
{
    struct node *t;
    if(head == NULL)
    {
        printf("\nno elements");
    }
    else
    {       
        printf("\nThe names are:\n");
        t = head;
        while(t != NULL)
        {
            printf("%s\n", t->name);
            t = t->next;
        }
    }
}

void sort()
{
    struct node *i, *j;
    char *temp;
    for(i = head; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(strcmp(i->name, j->name) > 0)
            {
                temp = i->name;
                i->name = j->name;
                j->name = temp;
            }
        }
    }
}

void reverse()
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int count()
{
    struct node *t = head;
    int count = 0;
    while(t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}
int main()
{
    int ch;
    char name[100];
    printf("\tMENU");
    printf("\n*********************");
    printf("\n*  1.INSERT         *");
    printf("\n*  2.DELETE         *");
    printf("\n*  3.DISPLAY        *");
    printf("\n*  4.SORT           *");
    printf("\n*  5.REVERSE        *");
    printf("\n*  6.COUNT          *");
    printf("\n*  7.Exit           *");
    printf("\n*********************");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\nEnter the name:");
                    scanf("%s", name);
                    insert(name);
                    break;
            case 2: printf("\nEnter the name to delete:");
                    scanf("%s", name);
                    delete(name);
                    break;
            case 3: display();
                    break;
            case 4: sort();
                    printf("\nList sorted successfully!");
                    break;
            case 5: reverse();
                    printf("\nList reversed successfully!");
                    break;
            case 6: printf("\nNumber of elements in the list: %d", count());
                    break;
            case 7: printf("\n**EXIT**");
                    break;
            default: printf("WRONG CHOICE");
                    break;
        }
    } while(ch != 7);
    return 0;
}

