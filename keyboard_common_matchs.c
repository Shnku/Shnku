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
    for (int i = start; i < end; i++)
    {
        *p = s[i]; // p[j++] = s[i];
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

int is_contained(const char *str, char *word)
{
    if (*word == '\0' || *str == '\0')
        return 404;
    int count = 0;
    for (; *str; str++)
    {
        for (; *word; word++)
        {
            if (*str == *word)
                count++;
        }
    }
    return count != strlen(word);
}

int main()
{
    char str[] = "this is a demo akadsd youtoyr";
    // char *word = extract_word(str, 0, 5);
    // printf("\nword is:: %s", word);
    // free(word);
    int start = 0;
    for (int end = 1; end <= strlen(str); end++)
    // for (int end = 1; str[end]; end++) //!it cant read the lastword..
    {
        char *a = NULL;
        if (str[end] == ' ' || str[end] == '\0')
        {
            a = extract_word(str, start, end);
            printf("\nextracted word: _%s_\n== %s\n== %s\n== %s", a, keyboard[0], keyboard[1], keyboard[2]);

            for (int i = 0; keyboard[i] != NULL; i++)
            {
                int status = is_contained(keyboard[i], a);
                printf("\nstatus is: %d", status);
                if (status)
                {
                    printf("\tyes this is contains");
                }
            }
            start = end + 1;
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

// output..
/*
extracted word: _this_
== qwertyuiop
== asdfghjkl
== zxcvbnm
status is: 0
status is: 0
status is: 0
extracted word: _is_
== qwertyuiop
== asdfghjkl
== zxcvbnm
status is: 0
status is: 0
status is: 0
extracted word: _a_
== qwertyuiop
== asdfghjkl
== zxcvbnm
status is: 0
status is: 0    yes this is contains
status is: 0
extracted word: _demo_
== qwertyuiop
== asdfghjkl
== zxcvbnm
status is: 0
status is: 0
status is: 0
extracted word: _akadsd_
== qwertyuiop
== asdfghjkl
== zxcvbnm
status is: 0
status is: 1    yes this is contains
status is: 0
extracted word: _youtoyr_
== qwertyuiop
== asdfghjkl
== zxcvbnm
status is: 0
status is: 0
status is: 0⏎
*/
