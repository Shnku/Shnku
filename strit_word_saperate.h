#include <stdio.h>
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
    int lst_sps_indx;
    for (int i; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            lst_sps_indx = i;
    }
    // printf("\nlst spc indx: %d", lst_sps_indx);
    char new_str[50];
    int nu_indx = 0;
    new_str[nu_indx++] = str[0];
    for (int i = 1; str[i] != '\0'; i++)
    {
        if (i == lst_sps_indx)
            break;
        else if (str[i] == ' ')
        {
            new_str[nu_indx++] = '.';
            new_str[nu_indx++] = str[i + 1];
        }
    }
    new_str[nu_indx++] = '.';
    for (int i = lst_sps_indx; str[i]; i++)
    {
        new_str[nu_indx++] = str[i];
    }
    printf("\nThe string is: %s", new_str);
}
