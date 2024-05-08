//Use malloc to read n integers and find the mean.

#include <stdio.h>
#include <stdlib.h>
int main() 
{      
    int n, i, *p, sum = 0;
    float m;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    p = (int *)malloc(sizeof(int) * n);
    if (p == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (i = 0; i < n; i++) 
    {
        sum += p[i];
    }
    m=sum / n;
    printf("Mean = %f",m) ;
    free(p);
    return 0;
}

