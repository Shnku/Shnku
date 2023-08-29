#include <stdio.h>
#include <string.h>
int is_contained(char *str, char *word)
{
    if (*word == '\0')
        return 404;

    char *p = word;
    int len = 0;
    while (*p)
    {
        len++;
        p++;
    }
    printf("\nlen= %d, strlen(word)=%d", len, strlen(word));

    int count = 0;
    while (*str != '\0')
    {
        char *pp = word; // Reset the pointer to the beginning of pp
        while (*pp != '\0')
        {
            if (*str == *pp)
            {
                printf("\n%c=%c", *pp, *str);
                count++;
            }
            pp++;
        }
        printf("\tcount= %d", count);
        str++;
    }
    printf("\tcount==len? %d==%d", count, len);
    return count == len;
}

int main()
{
    char str[] = "akhsdj is a demo string";
    int status = is_contained("asdfghjkl", "akhsdj");
    printf("\nstatus code: %d", status);
    return 0;
}
