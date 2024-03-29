#include <stdio.h>
#define ListItem 5

char nolist[ListItem][20] = {"perfectNo", "krishnamurtyNo", "armstrongNo", "palindroneNo", "squaresum"};
long facto(int n);
long power(int n, int p);
int no_of_digit(int n);
void printchoicelist(void);
void cheaker(int no, int key);

int main()
{
    int num, choice;
    printf("\nenter the number: ");
    scanf("%d", &num);

    printchoicelist();
    printf("\n\nEnter yer choice:  ");
    scanf("%d", &choice);

    cheaker(num, choice);

    return 0;
}

void cheaker(int no, int choice)
{
    int copy = no;
    int rem;
    int sum = 0;
    choice -= 1;

    while (copy)
    {
        rem = copy % 10;
        switch (choice)
        {
        case 0:
            sum += rem;
            break;

        case 1:
            sum += facto(rem);
            break;

        case 2:
            sum += power(rem, no_of_digit(no));
            break;

        case 3:
            sum = sum * 10 + rem;
            break;

        case 4:
            sum += power(rem, 2);
            break;

        default:
            printf("\nneed proper choice....");
            break;
        }
        copy /= 10;
    }
    printf("\nIS THE NO %s? %s", nolist[choice], no == sum ? "yes" : "no");
}

long facto(int n)
{
    return n == 1 || n == 0 ? 1 : n * facto(n - 1);
}

long power(int n, int p)
{
    return p == 0 ? 1 : n * power(n, p - 1);
}

int no_of_digit(int n)
{
    int rem, i = 0, len = 0;
    while (n)
    {
        rem = n % 10;
        n /= 10;
        len++;
    }
    return len;
}

void printchoicelist(void)
{
    printf("\nAvailable choices are...\n");
    for (int i = 0; i < ListItem; i++)
    {
        printf("\n(%d) |%s|  ", i + 1, nolist[i]);
    }
}

// output...
/*

enter the number: 4221224

Available choices are...

(1) |perfectNo|
(2) |krishnamurtyNo|
(3) |armstrongNo|
(4) |palindroneNo|
(5) |squaresum|

Enter yer choice:  4

IS THE NO palindroneNo? yes
*/
