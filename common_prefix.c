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

int main()
{
    char *str[] = {"this", "thi", "th"};
    char *a;
    a = get_prefix(str, 3);
    printf("\nthe output is:%s", a);
    free(a);
    return 0;
}

/*
if you do not realloc the temp pointer to a size of (i + 1) * sizeof(char), the temp[i] = '\0' 
statement will write a null character to a memory location that is outside of the memory block that is pointed to by the temp pointer. 
This will cause a segmentation fault.
*/
