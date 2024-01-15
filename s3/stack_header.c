#include <stdio.h>
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
    return s->top == MAX;
}

void push(stack *sp, int item)
{
    sp->arr[++sp->top] = item;
}

int pop(stack *sp)
{
    return sp->arr[sp->top--];
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
    while (sp.top != 0)
    {
        printf("%d\t", sp.arr[sp.top]);
        sp.top--;
    }
    printf("\n");
}

void init_stk(stack *sp)
{
    sp->top = -1;
}

// /*
int main()
{
    stack s1;
    push(&s1, 30);
    push(&s1, 40);
    push(&s1, 50);
    push(&s1, 60);
    show_stk(s1);
    printf("%d\n", peek(s1));
    printf("%d\n", pop(&s1));
}
// */