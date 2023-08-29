#include <stdio.h>
int is_contained(char *str, char *word)
{
    if (*word == '\0')
        return 404;

    int len = 0;
    while (*word)
    {
        len++;
        word++;
    }
    printf("\nlen= %d", len);

    int count = 0;
    for (; *str; str++)
    {
        for (; *word; word++)
        {
            if (*str == *word)
            {
                printf("%c=%c", *word, *str);
                printf("\tcount= %d", count);
                count++;
            }
        }
    }
    printf("\tcount= %d", count);
    return count == len;
}

int main()
{
    char str[] = "this is a demo string";
    int status = is_contained(str, "this");
    printf("%d", status);
    return 0;
}
