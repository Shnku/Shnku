#include <stdio.h>

int sum(int);

int main()
{
    int n;
    printf("en the nth degit: ");
    scanf("%d",&n);

    printf("the result is: %d",sum(n));
    printf("\n\n");
    return 0;
}

int sum(int nth)
{
    if(nth==1){
        return nth;
    }
    return nth+sum(nth-1);
}