#include <stdio.h>

int sum(int);
int sum_reve(int);

int main()
{
    int n;
    printf("en the nth degit: ");
    scanf("%d", &n);

    printf("\nthe result is: %d", sum(n));
    printf("\n\n");
    return 0;
}

int sum(int nth)
{
    if (nth == 1)
    {
        printf("\nif turu: %d", nth);
        return nth;
    }
    printf("\n%d + sum(%d)", nth, nth - 1);
    return nth + sum(nth - 1);
}

