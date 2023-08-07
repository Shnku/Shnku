/*
Given an array of strings words, return the words
that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *keyboard[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm", NULL};
// NULL is seninel value..

char *extract_word(char *s, int start, int end)
{
    char *p = calloc((end - start + 1), sizeof(char));
    for (int i = start; i < end || *s == '\0'; i++)
    {
        *p = s[i];
        p++;
    }
    *p = '\0';
    return p; // free it in main;
}

int get_prefix(char *str, char *word)
{
    int point = 0;
    char *temp;
    while (*str || *word)
    {
        point = (*str == *word) ? point + 1 : 0;
        str++;
        word++;
    }
    return point == strlen(word);
}



int main()
{
    char *a;
    printf("\nthe output is:%s", a);
    free(a);
    return 0;
}
