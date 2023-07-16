#include <stdio.h>
#define FUN(i, j) i##j
int main()
{
    int v1 = 10;
    int v2 = 20;
    printf("\n%d", FUN(v, 1));

    return 0;
}

// output..
/*
d "/home/shanku/Documents/GitHub/Shnku/"
 && gcc macro.c -o macro && "/home/shanku/Docu
ments/GitHub/Shnku/"macro

10⏎
*/
