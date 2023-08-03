#include <stdio.h>
#include <stdlib.h>
char *get_prefix(char **str, int len)
{
    char *temp = NULL;
    int i;
    for (i = 0; str[0][i] != '\0'; i++)
    {
        temp = (char *)realloc(temp, (i + 1) * sizeof(char));
        // make i+2 to fix that error...cause no space for null allocated
        temp[i] = str[0][i];
    }
    temp[i] = '\0'; // i got an error in leetcode
    for (int i = 1; i < len; i++)
    {
        for (int j = 0; str[i][j]; j++)
        {
            if (temp[j] != str[i][j])
            {
                temp[j] = '\0';
                break;
            }
        }
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
    char *str[] = {"thisisdffds1", "thision", "thisition"};
    // test(str[0]);
    char *a;
    a = get_prefix(str, 3);
    printf("\nthe output is:%s", a);
    free(a);
    return 0;
}
