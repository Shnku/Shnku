/*
Snow Howler is the librarian at the central library of the city of HuskyLand. He must handle requests which come in the following forms:

1 x y : Insert a book with y pages at the end of the xth shelf.
2 x y : Print the number of pages in the yth book on the xth shelf.
3 x : Print the number of books on the xth shelf.

Snow Howler has got an assistant, Oshie, provided by the Department of Education. Although inexperienced, Oshie can handle all of the queries of types 2 and 3.
*/

/*
Sample Input 0.............
5
5
1 0 50
1 0 20
1 2 78
2 2 0
3 0

Sample Output 0.............
78
2

Explanation 0.....................................
There are 5 shelves and 5 requests,or queries.
- 1 Place a 50 page book at the end of shelf 0.
- 2 Place a 20 page book at the end of shelf 0.
- 3 Place a 78 page book at the end of shelf 2.
- 4 The number of pages in the 0th book on the shelf 2 is 78.
- 5 The number of books on the 0th shelf is 2.
*/

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
