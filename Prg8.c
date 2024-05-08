//Two-dimensional matrix: using functions  - Multiplication
#include <stdio.h>

int m, n, i, j, a[10][10], b[10][10], c[10][10];

void insert() 
{
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &m, &n);

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &b[i][j]);
        }
    }
}

void display(int matrix[10][10]) 
{
    printf("\nMatrix:\n");
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}


void multiplication() 
{
    int k;
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++) 
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    display(c);
}

int main() 
{
    insert();
    printf("\nFirst Matrix:\n");
    display(a);
    printf("\nSecond Matrix:\n");
    display(b);
    multiplication();
    return 0;
}
