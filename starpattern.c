#include <stdio.h>

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

// output..
/*
en no of row...5
*-------*
**-----**
***---***
****-****
*/
