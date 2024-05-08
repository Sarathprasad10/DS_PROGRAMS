//Implement stack operations using arrays.
#include <stdio.h>

int push(int arr[], int pos) 
{   
    int element;
    if (pos == 9) 
    {
        printf("Stack is full\n");
        return pos;
    }
    printf("Enter element: ");
    scanf("%d", &element);
    arr[++pos] = element;
    return pos;
}

int pop(int arr[], int pos) 
{
    if (pos == -1) 
    {
        printf("Stack is Empty\n");
        return pos;
    }
    printf("%d is popped from the stack\n", arr[pos--]);
    return pos;
}

int peek(int arr[], int pos) 
{
    if (pos == -1) 
    {
        printf("Stack is Empty\n");
        return -1; 
    }
    return arr[pos];
}

int main() 
{
    int arr[10], top = -1, ch, pos = -1;
    printf("***********************\n");
    printf("1.Push\t\t2.Pop\n3.Peek\t\t4.Exit\n ");
    do {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                pos = push(arr, pos);
                break;
            case 2:
                pos = pop(arr, pos);
                break;
            case 3: 
            {
                int element = peek(arr, pos);
                if (element != -1) 
                {
                    printf("%d is on the top from the stack\n", element);
                }
                break;
            }
            case 4:
                printf("**EXIT**\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (ch != 4);

    return 0;
}
