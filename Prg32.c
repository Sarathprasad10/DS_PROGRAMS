//Use realloc to implement varchar for any length.
#include<stdlib.h>
#include<stdio.h>
void main()
{
char ch,*ptr;
int i=0;
printf("Enter the string: ");
ptr=(char *)malloc(sizeof(char));
do
{
scanf("%c",&ch);
*(ptr+i)=ch;
i++;
ptr=(char *) realloc(ptr,sizeof(char)*(i+1));
}
while(ch!= '\n');
*(ptr+i)='\0';
printf("\n------------------------------\n");
printf("The string entered is");
printf("\n------------------------------\n");
printf( "%s",ptr);
}

