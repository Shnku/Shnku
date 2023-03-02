#include <stdio.h>
int sum(int a)
{
    int i = 0;
    if (i == a)
        return a;
    else
        return a - sum(i + 1);
}
int main()
{
    int n;
    printf("en the nth degit: ");
    scanf("%d", &n);

    printf("\nthe result is: %d", sum(n));
    printf("\n\n");
    return 0;
}
