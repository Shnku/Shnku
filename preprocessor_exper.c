#include <stdio.h>

#define NUM 123
#define print printf("\n__CUSTOM MACRO LIKE FUNCTION__");
#define FUNC(X) X + 1

int main()
{
    printf("\nthis is abillbow.........%d.\n", NUM);
    print; // or just print no need semicolon..
    int a = 10;
    FUNC(a);
    printf("\na== %d", a);
    return 0;
}

/*output*/
/*

this is abillbow.........123.

__CUSTOM MACRO LIKE FUNCTION__
a== 10
*/
