#include <stdio.h>
int sum(int a)
{
    int i = 1; //! this will cause problem cause for each function call i set to 1;
    if (i == a)
    {
        printf("\n%d", a);
        return a;
    }
    else
    {
        printf("\n%d - sum(%d+1)", a, i);
        return a - sum(i + 1);
    }
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
