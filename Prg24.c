//Read a polynomial and display it; use structure array
#include <stdio.h>

struct poly
{
    int exp;
    int coeff;
};

void disp()
{
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    struct poly terms[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &terms[i].coeff);
        printf("Enter the exponent: ");
        scanf("%d", &terms[i].exp);
    }
    printf("The polynomial is: ");
    for (i = 0; i < n; i++)
    {
        printf("%dX^%d", terms[i].coeff, terms[i].exp);
        if (i < n - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    disp();
    return 0;
}
#include <stdio.h>

struct poly
{
    int exp;
    int coeff;
};

void disp()
{
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    struct poly terms[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &terms[i].coeff);
        printf("Enter the exponent: ");
        scanf("%d", &terms[i].exp);
    }
    printf("The polynomial is: ");
    for (i = 0; i < n; i++)
    {
        printf("%dX^%d", terms[i].coeff, terms[i].exp);
        if (i < n - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    disp();
    return 0;
}
