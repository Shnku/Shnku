#include <stdio.h>
int main()
{
    printf("\nen no of row...");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            printf("  ");
        }
        for (int k = 0; k < 2 * i - 1; k++)
        {
            printf("A ");
        }
        printf("\n");
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = n; j > i; j--)
        {
            printf("  ");
        }
        for (int k = 0; k < 2 * i - 1; k++)
        {
            printf("A ");
        }
        printf("\n");
    }
}

// output..
/*
en no of row...3

    A
  A A A
A A A A A
  A A A
    A
*/

#if 0
int main()
{
    printf("\nen no of row...");
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        for (int k = 1; k <= (2 * n) - (2 * i - 1); k++)
        {
            printf("-");
        }
        for (int l = 1; l <= i; l++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

#endif

// output..
/*
en no of row...5
*-------*
**-----**
***---***
****-****
*/
