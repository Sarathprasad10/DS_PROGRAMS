//Two-dimensional matrix: using functions  - Addition
#include <stdio.h>

int m, n, i, j, a[10][10], b[10][10], c[10][10];

void insert() {
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &m, &n);

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }
}

void display(int matrix[10][10]) {
    printf("\nMatrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void sum() {
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    display(c);
}
int main() {
    insert();
    printf("\nFirst Matrix:\n");
    display(a);
    printf("\nSecond Matrix:\n");
    display(b);
    sum();
   
    return 0;
}
