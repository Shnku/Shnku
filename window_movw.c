#include <stdio.h>
#define max 20
#define may 80
int x = 5, y = 5;
int box[max][may];

int drawbox()
{
    system("clear");
    for (int i = 0; i <= max; i++)
    {
        for (int j = 0; j <= may; j++)
        {
            if (i == 0 || i == max || j == 0 || j == may)
                printf("!");

            else if (box[i][j] == x && box[i][j] == y)
                printf("*");

            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

int main()
{
    drawbox();
    int key;
    printf("\nenter wherer to move: \n");
label:
    key = getchar();
    switch (key)
    {
    case 'a':
    case 'A':
        x--;
        drawbox();
        goto label;
        break;
    case 'd':
    case 'D':
        x++;
        drawbox();
        goto label;
        break;
    case 'w':
    case 'W':
        y++;
        drawbox();
        goto label;
        break;
    case 's':
    case 'S':
        y--;
        drawbox();
        goto label;
        break;
    default:
        break;
    }

    return 0;
}
