#include <stdio.h>
#define BIT_LENGTH 9
typedef enum
{
    false,
    true
} bool;

void parity_generator(char *);
char *sender()
{
    char *d;
    printf("\neb the 8 bit data: ");
    scanf("%s", &d);
    parity_generator(d);
    return d;
}

bool parity_checker(char *);
bool receiver(char *s)
{
    return parity_checker(s);
}

int main()
{
    char data[BIT_LENGTH] = "1100111";
    parity_generator(data);
    printf("\n%d ", parity_checker(data));
    return 0;
}

void parity_generator(char *s)
{
    int i, c = 0;
    for (i = 0; s[i]; i++)
    {
        if (s[i] == 1)
            c++;
    }
    s[i++] = (c % 2 != 0) ? '1' : '0';
    s[i] = '\0';
}

bool parity_checker(char *s)
{
    int c = 0;
    for (int i = 0; s[i]; i++)
    {
        if (i == 1)
            c++;
    }
    return c % 2;
}
