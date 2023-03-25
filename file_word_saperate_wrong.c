#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void word_saperate1(FILE *);
void word_saperate_2(FILE *);

int main()
{
    FILE *fp;
    if ((fp = fopen("file.txt", "r")) == NULL)
    {
        printf("\ncannot open file:  ");
        exit(0);
    }

    // word_saperate1(fp);
    /*enter the word to search: this
    fish: “"/workspaces/Shnku/"file_word_s…” terminated by signal SIGSEGV (Address boundary error)*/

    word_saperate_2(fp);

    return 0;
}

void word_saperate1(FILE *fp)
{
    int flag = 0;
    char word[12];
    printf("\nenter the word to search: ");
    fgets(word, 12, stdin);

    while (!feof(fp))
    {
        int i = 0;
        char temp[12], ch;
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
}

void word_saperate_2(FILE *fp)
{
    char word[20];
    int flag = 0;
    printf("\nEnter the word to search: ");
    fgets(word, 20, stdin);

    rewind(fp); // reset file pointer

    char temp[12];
    while (fscanf(fp, "%s", temp) != EOF)
    {
        if (strcmp(temp, word) == 0)
        {
            flag = 1; // set flag to 1 when match found
            break;    // exit loop after finding match
        }
    }
    flag ? printf("\nmatch") : printf("\nnot match");
}
