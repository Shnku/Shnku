#include <stdio.h>
void word_sap(char *str)
{
    char *word;
    int i = 0, j;
    while (str[i] != '\0')
    {
        j = 0;
        while (1)
        {
            if (str[i] == ' ' || str[i] == '\0')
            {
                break;
            }
            word[j] = str[i];
            i++, j++;
        }
        word[j] = '\0';
        printf("\n%s", word);
    }
}

void main()
{
    char s[50];
    printf("en the sen: ");
    fgets(s, 50, stdin);
    word_sap(s);
}
