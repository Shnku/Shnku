#include <stdio.h>
#define BIT_LENGTH 8
typedef enum
{
    false,
    true
} bool;
char data[BIT_LENGTH + 1];

void sender()
{
    printf("\neb the 8 bit data: ");
    scanf("%s", &data);
    data[BIT_LENGTH] = '\0';

    int c = 0;
    for (int i = 0; i < BIT_LENGTH; i++)
    {
        if (data[i] == '1')
            c++;
    }
    data[BIT_LENGTH] = (c % 2 != 0) ? '1' : '0';
    data[BIT_LENGTH + 1] = '\0';
}

bool receiver()
{
    printf("\nreceived data: %s", data);
    int c = 0;
    for (int i = 0; i < BIT_LENGTH; i++)
    {
        if (data[i] == '1')
            c++;
    }
    return c % 2 == 0;
}

void transmit()
{
    int d = 0;
    printf("\nwanna introduce error? 0 or 1: ");
    scanf("%d", &d);
    if (d)
        data[0] = (data[0] == '1') ? '0' : '1';
}

int main()
{
    sender();
    printf("\nsended data : %s", data);
    transmit();
    printf("\nerror ststus : %s  ", receiver() ? "Error detected" : "No error detected");
    return 0;
}

/*
eb the 8 bit data: 10101101

sended data : 101011011
wanna introduce error?0

received data: 101011011
error ststus : No error detected
*/

/*
eb the 8 bit data: 10101101

sended data : 101011011
wanna introduce error?1

received data: 001011011
error ststus : Error detected
*/
