#include <stdio.h>
#include <string.h>

int get_2d_str_size(char *s[])
{
    int count = 0;
    while (s[count] != NULL)
    {
        count++;
    }
    return count;
}

int main()
{
    char *str[] = {"nutbolt", "monday", "sun", "july", "aug",NULL};
    printf("\nThe number of elements is %d\n", get_2d_str_size(str));
    return 0;
}
