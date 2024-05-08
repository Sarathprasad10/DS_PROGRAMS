//Read a polynomial and display it; use array
#include<stdio.h>
int i,n,a[10];;
void display()
{
		printf("\nthe polonomial is:");
		for(i=n;i>=0;i--)
		{
			printf("%dX^%d",a[i],i);
			if(i!=0)
			{
				printf("+");
			}
			else
			{
					printf("\t");
			}
			
		}
}
int main()
{

		printf("enter the highest degree of the polonomial:");
		scanf("%d",&n);
		for(i=n;i>=0;i--)
		{		printf("enter the coifficent of X^%d: ",i);
				scanf("%d",&a[i]);
		}
		display();
		return 0;
		
}
