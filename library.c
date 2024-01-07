/*
Snow Howler is the librarian at the central library of the city of HuskyLand. He must handle requests which come in the following forms:

1 x y : Insert a book with y pages at the end of the x shelf.

2 x y : Print the number of pages in the y book on the x shelf.

3 x : Print the number of books on the x shelf.
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int *nob_in_sf;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int **bk_pg;

int main()
{
    int sf_no;
    printf("\nen total no of shelvers: ");
    scanf("%d", &sf_no);

    int q_no;
    printf("\nen total no of quary: ");
    scanf("%d", &q_no);

    nob_in_sf = (int *)malloc(q_no * sizeof(int));

    bk_pg = (int **)malloc(sf_no * sizeof(int *));
    for (int i = 0; i < sf_no; i++)
    {
        nob_in_sf[i] = 0;
        bk_pg[i] = (int *)malloc(0 * sizeof(int));
    }

    while (q_no--)
    {
        int q_typ;
        printf("\nen the type of quary: x=self // y=pages");
        printf("\ntype 1: x y insert book ");
        printf("\ntype 2:x y number of pages in the y ");
        printf("\ntype 3: x number of books on the x shelf.\n");

        scanf("%d", &q_typ);

        if (q_typ == 1)
        {
            int x, y;
            scanf("%d %d", &x, &y);

            int *lst_bk_idx = nob_in_sf - 1;
            nob_in_sf[x]++;
            bk_pg[x] = realloc(bk_pg[x], nob_in_sf[x] * sizeof(int *));
            bk_pg[x][nob_in_sf[x] - 1] = y;
        }
        else if (q_typ == 2)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(bk_pg + x) + y));
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(nob_in_sf + x));
        }
    }

    if (nob_in_sf)
    {
        free(nob_in_sf);
    }

    for (int i = 0; i < sf_no; i++)
    {
        if (*(bk_pg + i))
        {
            free(*(bk_pg + i));
        }
    }

    if (bk_pg)
    {
        free(bk_pg);
    }

    return 0;
}
