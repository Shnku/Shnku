#include <stdio.h>

int power(int no, int r)
{
    if (r == 0)
        return 1;
    return no * power(no, r - 1);
}

int no_of_digit(int n)
{
    int count = 0;
    while (n)
    {
        n = n / 10;
        count++;
    }
    return count;
}

int sqr_each_digit(int no)
{
    int sum = 0;
    while (no)
    {
        int rem = no % 10;
        int p = (int)power(rem, 2);
        int n = no_of_digit(sum);
        sum = p * power(10, n) + sum;
        no /= 10;
    }
    return sum;
}

int main()
{
    printf("%d", no_of_digit(4264267));
    printf("\n%d", sqr_each_digit(4351));
    return 0;
}

/*
done 
7
169251⏎  
*/
