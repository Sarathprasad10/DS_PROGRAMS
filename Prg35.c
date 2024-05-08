//Demonstrate a linked list creation and display
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insert(int e)
{ 
    struct node*t;
    if(head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node));
        head->data=e;
        head->next=NULL;
    }
   else
    { 
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=(struct node*)malloc(sizeof(struct node));
        t->next->data=e;
        t->next->next=NULL;
    }
}
void delete(int e)
{
    struct node*t;
    if(head==NULL)
    {
        printf("\nno elemnets");
    }
    else if(head->data==e&&head->next==NULL)
    {
        printf("\n%d the element is removed",e);
            head=NULL;
    }
    else if(head->data==e&&head->next!=NULL)
    {
        printf("\n%d the element is removed",e);
        head=head->next;
    }
    else
    {   t=head;
            while(t->next->data!=e&&t->next->next!=NULL)
            {
                    t=t->next;
            }
            if(t->next->data==e)
            {
                    printf("\n%d is deleted", e);
                    t->next=t->next->next;
            }
            else
            {
                  printf("\nelement not found");
            }
    }
}

void display()
{
        struct node*t;
        if(head==NULL)
        {
                printf("\nno elements");
        }
        else
        {       printf("\nthe elements are:\n");
        t=head;
                while(t!=NULL)
                {
                        printf("%d\t",t->data);
                        t=t->next;
                }
        }
}

int main()
{
    int ch,n;
    printf("\tMENU");
    printf("\n*********************");
    printf("\n*  1.INSERT         *");
    printf("\n*  2.DELETE         *");
    printf("\n*  3.DISPLAY        *");
    printf("\n*  4.Exit           *");
    printf("\n*********************");
    do{
          printf("\nEnter your choice:");
          scanf("%d",&ch);
          switch(ch)
          {
                case 1: printf("\nEnter the number:");
                        scanf("%d",&n);
                        insert(n);
                        break;
                 case 2: printf("\nEnter the number to delete:");
                        scanf("%d",&n);
                        delete(n);
                        break;
                 case 3:display();
                        break;
                case 4:printf("\n**EXIT**");
                        break;
                default:printf("WRONG CHOICE");
                        break;
                
          }
    }while(ch!=4);
}

