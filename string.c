#include <stdio.h>
#include "strit_word_saperate.h"

void main()
{
    char s[50];
    printf("en the sen: ");
    fgets(s, 50, stdin);
    // word_sap(s);

    short_name_maker(s);
}
