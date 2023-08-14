

#include <stdio.h>
#include <stdlib.h>

// int *total_number_of_books;
// int **total_number_of_pages;

int no_of_shelf, no_of_quary;
int **book;
int book_count = 0;
void calculate(int, int, int);

int main()
{
    printf("\nenter shelf no and how meny quaries? ");
    scanf("%d%d", &no_of_shelf, &no_of_quary);

    book = (int **)malloc(no_of_shelf * sizeof(int *));
    for (int i = 0; i < no_of_quary; i++)
    {
        book[i] = (int *)malloc(book_count * sizeof(int));
    }

    // quarry..
    for (int i = 0; i < no_of_quary; i++)
    {
        int key;
        int x, y;
        printf("\nen the choice:/1/2/3|| x || y : ");
        scanf("%d%d%d", &key, &x, &y);
        calculate(key, x, y);
    }

    free(book);
    for (int i = 0; i < book_count; i++)
    {
        free(book[i]);
    }

    return 0;
}

void calculate(int key, int a, int b)
{
    switch (key)
    {
    case 1:
        printf("\nplacing the book :");
        book_count += 1;
        book[book_count] = realloc(book, book_count * sizeof(int *));
        book[a][book_count] = b;
        break;
    case 2:
        printf("\nno of page in %d book on %d shlef is: %d", b, a, book[a][b]);
        break;
    case 3:
        printf("\nno of books in the %d shelf is: %d", a, book_count);
        break;
    }
}
