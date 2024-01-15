#include <stdio.h>

#include "stack_header.c"
bool p_check(char *exp)
{
    stack stk;
    bool flag;
    while (*exp)
    {
        printf("\n pnt to  %c...", *exp);
        if (*exp == '(' || *exp == '{' || *exp == '[')
        {
            printf("\n inside if1...");
            push(&stk, *exp);
            show_stk(stk);
        }
        if (*exp == ')' || *exp == '}' || *exp == ']')
        {
            printf("\n inside if2...");
            char s = (char)pop(&stk);
            printf("\n popped elemt: %d==%c", s, s);
            printf("\n %c==%c ? ", s, *exp);
            switch (s)
            {
            case '(':
                if (*exp != ')')
                    return false;
                break;
            case '{':
                if (*exp != '}')
                    return false;
                break;
            case '[':
                if (*exp != ']')
                    return false;
                break;
            default:
                break;
            }
        }
        exp++;
    }
    printf("\n is stk empty?? %d", isempty(&stk));
    show_stk(stk);
    return (isempty(&stk)) ? true : false;
}

int main()
{
    char exp[MAX];
    printf("Enter the exp:: ");
    scanf("%s", &exp);
    printf("\n exp is : %s", p_check(exp) ? "ok" : "not ok");
    return 0;
}
