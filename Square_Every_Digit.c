#include <stdio.h>

int no_of_digit(int n);
int power(int no, int r);
int sqr_each_digit(int no);
int square_each_digit2(int no);

int each_digt_sqr(int no)
{
    int sum = 0;
    int digit_count = no_of_digit(no);
    while (digit_count) // same..while (no)
    //! imp: while(no) not works if last digit 0..
    {
        int tent = power(10, digit_count - 1);
        int qus = no / tent;
        int dig_of_pow, p;
        if (qus == 0)
            sum = sum * 10;
        else
        {
            p = power(qus, 2);
            dig_of_pow = no_of_digit(p);
            sum = sum * power(10, dig_of_pow) + p;
            no = no % tent;
        }
        printf("\ntens = %d ", tent);
        printf("\nqus = %d ", qus);
        printf("\tpower = %d ", p);
        printf("\tdig of power = %d ", dig_of_pow);
        printf("\nsum=%d\tno=%d\n", sum, no % tent);
        digit_count--;
    }
    return sum;
}

int main()
{
    printf("\n%d", each_digt_sqr(205309));
    printf("\nen a no to find : ");
    int no;
    scanf("%d", &no);
    printf("\n%d", each_digt_sqr(no));

    // printf("\n%d", square_each_digit2(205309)); // 425981
    // printf("\n%d", sqr_each_digit(4351));       // 16*10^4 + 9*10^3 + 25*10^1 +1
    // printf("\n%d", sqr_each_digit(1001));       // 1111
    // printf("\n%d", sqr_each_digit(500507));     // 25 1 1 25 1 49
    // printf("\n%d", square_each_digit2(500507)); // 25 1 1 25 1 49

    return 0;
}

//________other functions_______________________//

int sqr_each_digit(int no)
{
    int sum = 0;
    while (no)
    {
        int rem = no % 10;
        // if (rem == 0)
        // {
        //     rem = 1;
        //     // not work ..
        // }
        int p = (int)power(rem, 2);
        int n = no_of_digit(sum);
        sum = p * power(10, n) + sum;
        no /= 10;
    }
    return sum;
}
/*
done
$gcc Square_Every_Digit.c -o Square_Every_Digit
$./Square_Every_Digit

169251
11⏎ //?how to solve this..
*/

int square_each_digit2(int no)
{
    int sum = 0;
    while (no)
    {
        int digit_no = no_of_digit(no);
        printf("\ndigit no = %d ", digit_no);
        int tent = power(10, digit_no - 1);
        printf("\ttens = %d ", tent);
        int qus = no / tent;
        printf("\nqus = %d ", qus);
        int p = power(qus, 2);
        printf("\tpower = %d ", p);
        int dig_of_pow = no_of_digit(p);
        printf("\tdig of power = %d ", dig_of_pow);
        sum = sum * power(10, dig_of_pow) + p;
        printf("\nsum=%d  no=%d\n", sum, no % tent);
        no = no % tent;
    }
    return sum;
}

/*
digit no = 6    tens = 100000
qus = 2         power = 4       dig of power = 1
sum=4  no=5309

digit no = 4    tens = 1000
qus = 5         power = 25      dig of power = 2
sum=425  no=309

digit no = 3    tens = 100
qus = 3         power = 9       dig of power = 1
sum=4259  no=9

digit no = 1    tens = 1
qus = 9         power = 81      dig of power = 2
sum=425981  no=0

425981 //! it should be 40259081.. not works..
*/

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

int power(int no, int r)
{
    if (r == 0)
        return 1;
    return no * power(no, r - 1);
}
