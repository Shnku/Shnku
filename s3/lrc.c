#include <stdio.h>
#include <string.h>
#define BIT_LENGTH 4
typedef struct lrc
{
    int frames;
    char matrix[BIT_LENGTH][BIT_LENGTH];
    int lrc[BIT_LENGTH];
} DATA;

typedef enum
{
    false,
    true
} bool;

void sender(DATA *d)
{
    for (int i = 0; i < BIT_LENGTH; i++)
        d->lrc[i] = 0;

    for (int i = 0; i < BIT_LENGTH; i++)
    {
        for (int j = 0; j < d->frames; j++)
        {
            if (d->matrix[j][i] == '1')
                d->lrc[i] = (d->lrc[i] + 1) % 2;
        }
    }
}
void transmit(DATA *d)
{
    int f = 0;
    printf("\nwanna introduce error? 0 or 1: ");
    scanf("%d", &f);
    if (f)
        d->matrix[0][f] = (d->matrix[0][f] == '1') ? '0' : '1';
}

bool receiver(DATA d)
{
    int templrc[BIT_LENGTH];
    for (int i = 0; i < BIT_LENGTH; i++)
        templrc[i] = 0;

    for (int i = 0; i < BIT_LENGTH; i++)
    {
        for (int j = 0; j < d.frames; j++)
        {
            if (d.matrix[j][i] == '1')
                templrc[i] = (templrc[i] + 1) % 2;
        }
    }
    // compare..
    for (int i = 0; i < BIT_LENGTH; i++)
    {
        if (templrc[i] != d.lrc[i])
            return false;
    }
    return true;
}

void display(DATA d);
int main()
{
    int n;
    printf("\nenter no of frame: ");
    scanf("%d", &n);

    DATA data;
    data.frames = n;
    // input data matrix..
    printf("enter frames...\n");
    for (int i = 0; i < n; i++)
        scanf("%s", &data.matrix[i]);

    display(data);
    sender(&data);
    display(data);
    printf("\ntransmit....");
    transmit(&data);
    printf("\nreceived....");
    display(data);
    printf("\nerror ststus : %s  ", receiver(data) ? "No Error detected" : "Error detected");
    return 0;
}

void display(DATA d)
{
    printf("\ndisplay data frame..\n");
    for (int i = 0; i < d.frames; i++)
    {
        for (int j = 0; j < BIT_LENGTH; j++)
        {
            printf(" %c", d.matrix[i][j]);
        }
        printf("\n");
    }
    printf("display lrc: ");
    for (int i = 0; i < BIT_LENGTH; i++)
        printf("%d ", d.lrc[i]);
}

/*

enter no of frame: 3
enter frames...
0101
1011
0011

display data frame..
 0 1 0 1
 1 0 1 1
 0 0 1 1
display lrc: 0 0 0 0
display data frame..
 0 1 0 1
 1 0 1 1
 0 0 1 1
display lrc: 1 1 0 1
transmit....
wanna introduce error? 0 or 1: 1

received....
display data frame..
 0 0 0 1
 1 0 1 1
 0 0 1 1
display lrc: 1 1 0 1
error ststus : Error detected  ⏎
*/

/*
enter no of frame: 3
enter frames...
0101
1011
0011

display data frame..
 0 1 0 1
 1 0 1 1
 0 0 1 1
display lrc: 0 0 0 0
display data frame..
 0 1 0 1
 1 0 1 1
 0 0 1 1
display lrc: 1 1 0 1
transmit....
wanna introduce error? 0 or 1: 0

received....
display data frame..
 0 1 0 1
 1 0 1 1
 0 0 1 1
display lrc: 1 1 0 1
error ststus : No Error detected  ⏎
*/
