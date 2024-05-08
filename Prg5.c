//Sort the array elements in ascending order (minimum three functions: read, disp and sort)
#include <stdio.h>

int a[10], n;

void insert() {
    int i;
    printf("Enter the size of the array (up to 10): ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void display() {
    int i;
    printf("\nThe array is:");
    for (i = 0; i < n; i++) {
        printf("\t%d", a[i]);
    }
    printf("\n");
}

void sort() {
    int temp = 0, i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\nThe sorted array is:");
    for (i = 0; i < n; i++) {
        printf("\t%d", a[i]);
    }
    printf("\n");
}

int main() {
    insert();
    display();
    sort();
    return 0;
}
