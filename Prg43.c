//Perform the respective operations on the following: Linked Stack

#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node* next;
};
struct node*top=NULL;
void push(int e)
{
        struct node* t;
        t=(struct node*)malloc(sizeof(struct node));
        t->data=e;
        t->next=top;                
        top=t;
}
void display()
{
        struct node* t;
        if(top==NULL)
        {
            printf("\nNo Elements:");
        }
        else
        {
            t=top;
            while(t!=NULL)
            {
                    printf("\n%d",t->data);
                    t=t->next;
                    
            }
                
        }
}
void pop()
{
        struct node *t;
        if(top==NULL)
        {
                printf("no elements");
        }
        else
        {
                printf("\n%d is popped",top->data);
                top=top->next;
        }
}
void peek()
{
        printf("\n%d is at top of stack",top->data);
}
int main()
{
    int ch;
    int n;
    printf("\tMENU");
    printf("\n*********************");
    printf("\n*  1.PUSH           *");
    printf("\n*  2.POP            *");
    printf("\n*  3.PEEK           *");
    printf("\n*  4.Exit           *");
    printf("\n*********************");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\nEnter the number:");
                    scanf("%d",&n);
                    push(n);
                    break;
            case 2: pop();
                    break;
            case 3:peek();
                    break;
            case 4: printf("\n**EXIT**");
                    break;
            default: printf("WRONG CHOICE");
                    break;
        }
    } while(ch != 4);
    return 0;
}


