#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    if ((fp = fopen("file.txt", "r")) == NULL)
    {
        printf("\ncannot open file:  ");
        exit(0);
    }

    char word[20], ch;
    int flag = 0;

    printf("\nEnter the word to search: ");
    fgets(word, 20, stdin);

    while ((ch = fgetc(fp)) != EOF)
    {
        int i = 0;
        char temp[12];
        while ((ch = fgetc(fp)) != ' ')
        {
            temp[i++] = ch;
        }
        temp[i] = '\0';
        if (strcmp(temp, word) == 0)
        {
            flag = 1;
            break;
        }
    }
    flag ? printf("\nmatch") : printf("\nnot match");

    return 0;
}
