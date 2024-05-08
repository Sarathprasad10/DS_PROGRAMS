//Write programs to demonstrate the use of storage classes in C.
#include <stdio.h>
int a = 30; // global variable
void local()
{
    int i = 40; // local variable
    printf("\nThe value of local variable: %d", i);
}
void stat()
{
    static int j = 0; // static variable
    printf("\nThe value of static variable is: %d ", j++);
}
int main()
{
    printf("**OUTPUT**");
    printf("\n-------------------------\n");
    printf("\nThe value of global variable is: %d", a);
    local();
    stat();
    stat();
    return 0;
}
