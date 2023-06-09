// #include <stdio.h>
void word_sap(char *str)
{
    char word[15];
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
        i++;
    }
}

void short_name_maker(char *str)
{
    char new_str[50];
    int indx_arr[5];
    int index = -1;
    for (int i = 0; *str; i++)
    {
        if (*str == ' ')
            indx_arr[++index] = i;
    }
    printf("\nindex is=no of space:  %d", index);
    while (*str != '\0')
    {
    }
}
