#include <stdio.h>

#include "stack_header.c"
bool p_check(char *exp)
{
    stack stk;
    init_stk(&stk); // this is important..
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

/*
Enter the exp:: 8-{6+(9+5)}

 pnt to  8...
 pnt to  -...
 pnt to  {...
 inside if1...
displaying stack....
123

 pnt to  6...
 pnt to  +...
 pnt to  (...
 inside if1...
displaying stack....
40      123

 pnt to  9...
 pnt to  +...
 pnt to  5...
 pnt to  )...
 inside if2...
 popped elemt: 40==(
 (==) ?
 pnt to  }...
 inside if2...
 popped elemt: 123=={
 {==} ?
 is stk empty?? 1
 stack is empty...
 exp is : ok
*/

/*
Enter the exp:: 8-{6+(9+5)

 pnt to  8...
 pnt to  -...
 pnt to  {...
 inside if1...
displaying stack....
123

 pnt to  6...
 pnt to  +...
 pnt to  (...
 inside if1...
displaying stack....
40      123

 pnt to  9...
 pnt to  +...
 pnt to  5...
 pnt to  )...
 inside if2...
 popped elemt: 40==(
 (==) ?
 is stk empty?? 0
displaying stack....
123

 exp is : not ok⏎
*/
