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
const char *keyboard[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm", NULL}; // NULL is seninel value..
void chek_memallocation(char *p);

char *extract_word(char *s, int start, int end)
{
    char *p = (char *)calloc((end - start + 1), sizeof(char));
    chek_memallocation(p);
    int j = 0; // we should do this..
    for (int i = start; i < end && s[i] != '\0'; i++)
    {
        p[j++] = s[i]; //*p=s[i] //!wrong
    }
    p[j] = '\0';
    return p; // free it in main; //!p-end-start+1;
}

int main()
{
    char str[] = "this is a demo sentense";
    int start = 0;
    char *word = extract_word(str, 0, 5);
    printf("\nwor %s", word);
    free(word);
    // for (int end = 1; str[end]; end++)
    // {
    //     char *a = NULL;
    //     if (str[end] == ' ')
    //     {
    //         a = extract_word(str, start, end);
    //         start = end;
    //     }
    //     for (int i = 0; keyboard[i] != NULL; i++)
    //     {
    //         int status = strcmp(keyboard[i], a);
    //         printf("%d", status);
    //     }
    //     free(a);
    // }
    return 0;
}

void chek_memallocation(char *p)
{
    if (!p)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
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
