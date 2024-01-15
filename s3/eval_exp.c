#include <stdio.h>
#include <stdlib.h>

#include "stack_header.c"
int eval_exp(char *s)
{
    stack stk;
    int result;
    init_stk(&stk);
    while (*s)
    {
        if (*s == '+' || *s == '-' || *s == '*' || *s == '/')
        {
            printf("\ninside if..");
            int out1 = pop(&stk);
            int out2 = pop(&stk);
            printf("\npops are %d, %d\n", out1, out2);
            char ex = *s;
            switch (ex)
            {
            case '+':
                result = out1 + out2;
                break;
            case '-':
                result = out1 - out2;
                break;
            case '*':
                result = out1 * out2;
                break;
            case '/':
                result = out1 / out2;
                break;
            default:
                break;
            }
            // show_stk(stk);
            push(&stk, result);
        }
        else
        {
            printf("\ninside else....%d-%d", *s, '0');
            // const char c = *s;
            // c = atoi(*s);
            push(&stk, *s - '0');
            // show_stk(stk);
        }
        s++;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    char s[MAX];
    int result;
    printf("en the expression in postfix:: ");
    scanf("%s", s);
    // fgets(s, MAX, stdin);
    printf("the exp is: %s", s);
    // fputs(s, stdout);
    result = eval_exp(s);
    printf("\nres is= %d", result);
    printf("\n");
    return 0;
}

/*
 ./eval_exp
en the expression: 34+9/8*
the exp is: 34+9/8*
inside else....51-48
inside else....52-48
inside if..
pops are 4, 3

inside else....57-48
inside if..
pops are 9, 7

inside else....56-48
inside if..
pops are 8, 1

res is= 8
*/