#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef struct stack
{
    int arr[MAX];
    int top;
} stack;

typedef enum
{
    false,
    true
} bool;

bool isempty(stack *s)
{
    return s->top == -1;
}

bool isfull(stack *s)
{
    return s->top == MAX - 1;
}

void push(stack *sp, int item)
{
    if (isfull(sp))
    {
        printf("\nOverflow");
        return;
    }
    sp->arr[++sp->top] = item;
}

int pop(stack *sp)
{
    if (isempty(sp))
    {
        printf("\nUnderflow");
        return -1;
    }
    return (sp->arr[sp->top--]);
}

int peek(stack sp)
{
    return sp.arr[sp.top];
}

void show_stk(stack sp)
{
    if (isempty(&sp))
    {
        printf("\n stack is empty...");
        return;
    }
    printf("\ndisplaying stack....\n");
    int i = sp.top;
    while (i >= 0)
    {
        printf("%d\t", sp.arr[i]);
        i--;
    }
    printf("\n");
}

void init_stk(stack *sp)
{
    sp->top = -1;
}

#if 0
int main()
{
    int choice, data;
    stack stk1;
    init_stk(&stk1);

    while (1)
    {
        printf("\nenter yer choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nperforming push...enter data:");
            scanf("%d", &data);
            push(&stk1, data);
            break;
        case 2:
            printf("\nperforming pop...");
            printf("\n%d poped;", pop(&stk1));
            break;
        case 3:
            show_stk(stk1);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
#endif
