#include <stdio.h>
int main()
{
    int no, i;
    printf("en the no: ");
    scanf("%d", &no);
    for (i = 2; i <= no / 2; i++)
    {
        if (no % i == 0)
        {
            printf("this is not prime\n");
            break;
        }
    }
    printf("this is prime\n");
}
