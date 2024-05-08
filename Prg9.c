//Two-dimensional matrix: using functions  - Transpose of a matrix
#include <stdio.h>
void inputMatrix(int matrix[10][10], int rows, int cols) 
{
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void transposeMatrix(int matrix[10][10], int transposed[10][10], int rows, int cols) 
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) 
        {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols) 
{
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int matrix[10][10], transposed[10][10], rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &rows, &cols);
    inputMatrix(matrix, rows, cols);
    printf("\nOriginal Matrix:\n");
    displayMatrix(matrix, rows, cols);
    transposeMatrix(matrix, transposed, rows, cols);
    printf("\nTransposed Matrix:\n");
    displayMatrix(transposed, cols, rows);
    return 0;
}

