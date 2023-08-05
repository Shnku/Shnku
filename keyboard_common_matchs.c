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
char *get_prefix(char **str, int len)
{
    if (len == 0)
        return "";

    char *temp = NULL;
    int i;
    for (i = 0; str[0][i] != '\0'; i++)
    {
        temp = (char *)realloc(temp, (i + 1) * sizeof(char));
        // make i+2 to fix that error...cause no space for null allocated
        temp[i] = str[0][i];
    }
    temp = (char *)realloc(temp, (i + 1) * sizeof(char));
    temp[i] = '\0';
    for (int i = 1; i < len; i++)
    {
        int j;
        for (j = 0; str[i][j]; j++)
        {
            if (temp[j] != str[i][j])
            {
                temp[j] = '\0';
                break;
            }
        }
        temp[j] = '\0';
    }
    printf("%s", temp);
    // char *t = temp;
    // return t;
    return temp;
}

void test(char *str)
{
    char *temp = str;
    printf("%s", temp);
}

int main()
{
    char *str[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    // test(str[0]);
    char *a;
    a = get_prefix(str, 3);
    printf("\nthe output is:%s", a);
    free(a);
    return 0;
}
