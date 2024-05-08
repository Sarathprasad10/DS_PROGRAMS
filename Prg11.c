//Display the array elements in the same order using a recursive function
#include <stdio.h>
int n,a[10],i;
void insert()
{
        printf("enter the size of array:");
        scanf("%d",&n);
        printf("enter the elements of the array:");
        for( i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
}
void display(int index)
{

    if(index>=n)
    {
        return;
    }
      
        printf("%d ",a[index]);
         display(index+1);
    
}
void main()
{       int index=0;
        insert();
        display(index);
}
