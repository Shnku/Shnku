// #include <stdio.h>
void swap(char *x, char *y);

int strlen(char *s)
{
    char *p = s;
    while (*s)
    {
        s++;
    }
    return (s - p) / sizeof(char);
    // return s-p; //this is works also..
}

/*saperate words form string............*/
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

/*This is a name maker.:  a.b.bag. like.....*/
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
    new_str[nu_indx++] = '.';
    for (int i = 1; str[i] != '\0'; i++)
    {
        if (i >= lst_sps_indx)
            new_str[nu_indx++] = str[i + 1]; // to skip space..

        else if (str[i] == ' ')
        {
            new_str[nu_indx++] = str[i + 1];
            new_str[nu_indx++] = '.';
        }
    }
    printf("\nThe string is: %s", new_str);
}

/*to short as alphabetically order abcd....*/
void alplabetical_order(char str[])
{
    int len = 0;
    char copy[50];
    int index = 0;
    while (*str)
    {
        len++;
        copy[index++] = *str; // copy needed ..edited actual string causing problem..
        str++;
    }
    printf("\nthe len is: %d", len);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (copy[j] > copy[j + 1])
            {
                swap(&copy[j], &copy[j + 1]);
                // copy[index++] = copy[j];
            }
        }
    }
    printf("\nnew string is : %s", copy);
}

/*swapping characters....*/
void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

int get_prefix(char *str, char *word)
{
    int point = 0;
    char *temp;
    while (*str || *word)
    {
        point = (*str == *word) ? point + 1 : 0;
        str++;
        word++;
    }
    return point == strlen(word);
}
