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
    printf("\n%d", sqr_each_digit(4351));
    // 16*10^4 + 9*10^3 + 25*10^1 +1
    printf("\n%d", sqr_each_digit(1001));

    return 0;
}

/*
done
$gcc Square_Every_Digit.c -o Square_Every_Digit
$./Square_Every_Digit

169251
11⏎ //?how to solve this..
*/
