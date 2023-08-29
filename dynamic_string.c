#include <stdio.h>
#include <stdlib.h>
char *append(char *s, char *w)
{
    char *str = malloc(0);
    int i = 0;
    while (s[i])
    {
        str = realloc(str, (i + 1) * sizeof(char));
        str[i] = s[i];
        i++;
    }
    while (*w)
    {
        str = realloc(str, (i + 1) * sizeof(char));
        str[i] = *w;
        i++;
        w++;
    }
    str = realloc(str, (i + 1) * sizeof(char));
    str[i] = '\0';
    s = str;
    return s;
}

int main()
{
    char *s = "this is the";
    s = append(s, "__this is appended");
    printf("\n%s", s);
    free(s);
    return 0;
}
