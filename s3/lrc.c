#include <stdio.h>
#include <time.h>
#define BIT_LENGTH 8
typedef enum
{
    false,
    true
} bool;

void transmit()
{
    srand(time(NULL));
    return rand() % 11; // Generates a random number between 0 and 10
}
char *sender(char *data)
{
    char *lrc;
    for (int i = 0; data[i]; i++)
    {
    }

    return lrc;
}
bool receiver(char *s)
{
    return parity_checker(s);
}

int main()
{
    char data[BIT_LENGTH * 4]; // 32 bit;
    printf("\nenter the data continiously: ");
    scanf("%s", &data);

    printf("\nenter the received data; ");
    return 0;
}
