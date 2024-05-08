//Search for all the occurrences of an element in an integer array (positions)
#include <stdio.h>

int a[10], n;

void insert() {
    printf("Enter the size of the array (up to 10): ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void search() {
    int e, i, found = 0;
    printf("Enter the element to search: ");
    scanf("%d", &e);
    for (i = 0; i < n; i++) {
        if (a[i] == e) {
            found = 1;
            printf("Element %d found at position %d\n", e, i + 1);
        }
    }

    if (!found) {
        printf("Element %d not found in the array\n", e);
    }
}

int main() {
    insert();
    search();
    return 0;
}
