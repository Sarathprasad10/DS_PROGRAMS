//Declare a structure for Books having author_name and book_name. Create an array of books using a pointer variable. Provide functions for reading n books and displaying the same using pointers.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book 
{
    char author_name[100];
    char book_name[100];
};
void readBooks(struct Book *books, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("Enter book name for book %d: ", i + 1);
        scanf("%s", books[i].book_name);
        printf("Enter author name for book %d: ", i + 1);
        scanf("%s", books[i].author_name);
    }
}

void displayBooks(const struct Book *books, int n) 
{
    printf("List of Books:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Book %d:\n", i + 1);
        printf("Book Name: %s\n", books[i].book_name);
        printf("Author Name: %s\n", books[i].author_name);

    }
}

int main() 
{
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);
    struct Book *books = (struct Book *)malloc(n * sizeof(struct Book));
    if (books == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    readBooks(books, n);
    displayBooks(books, n);
    free(books);
    return 0;
}

