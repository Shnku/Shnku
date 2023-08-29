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
const char *keyboard[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm", NULL}; // NULL is seninel..
void chek_memallocation(char *p);

char *extract_word(char *s, int start, int end)
{
    char *p = (char *)calloc((end - start + 1), sizeof(char));
    char *point_p = p;
    // printf("first: %u", p);
    chek_memallocation(p);
    // int j=0;
    for (int i = start; i < end && s[i] != '\0'; i++)
    {
        // p[j++] = s[i]; //*p=s[i] //!wrong
        *p = s[i];
        p++;
        // printf("\n%u", p);
    }
    *p = '\0';
    // printf("\nnew:\t%u \t %u", p, point_p);
    // printf("\n%u", p - end - start);
    // return p - end - start;
    return point_p; // free it in main; //!p-end-start;
}
/*
first: 3331895968
3331895969
3331895970
3331895971
3331895972
3331895973
new:    3331895973       3331895968
3331895968
word is:: this
*/

int is_contained(char *str, char *word)
{
    if (*word == '\0')
        return 0;
    int count = 0;
    while (*str && *word)
    {
        if (*str == *word)
        {
            count++;
            word++;
        }
        str++;
    }
    return count == strlen(word);
}

int main()
{
    char str[] = "this is a demo sentense";
    // char *word = extract_word(str, 0, 5);
    // printf("\nword is:: %s", word);
    // free(word);
    int start = 0;
    for (int end = 1; str[end]; end++)
    {
        char *a = NULL;
        if (str[end] != ' ')
            continue;
        else
        {
            a = extract_word(str, start, end);
            printf("\nextracted word: %s\n== %s\n== %s\n== %s", a, keyboard[0], keyboard[1], keyboard[2]);

            for (int i = 0; i < 3; i++)
            {
                int status = get_prefix(keyboard[i], a);
                printf("\nstatus is: %d", status);
            }
            start = end;
            free(a);
        }
    }
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
