#include <stdio.h>
int x = 15;
void first();
void second();

int main()
{
    extern int x;

    printf("\nin main x = %d", x);
    first();
    printf("\nin main x = %d", x);
    second();
    printf("\nin main x = %d", x);

    return 0;
}

void first()
{
    int x = 5;
    // x = 5;
    printf("\nx in first x=%d", x);
}

void second()
{
    x = 35;
    printf("\nx in first x=%d", x);
}
