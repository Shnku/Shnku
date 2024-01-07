#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;
typedef struct stack
{
    int data;
    struct stack *link;
} STACK;

bool isempty(STACK *stkptr);
bool isfull(STACK *stkptr);
void push(STACK **stkptr, int data);
int pop(STACK **stkptr);
int peek(STACK *stkptr);

int main()
{
    int choice, data;
    STACK *stk1;
    printf("\nenter yer choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\nperforming push...");
        push(&stk1, data);
        break;
    case 2:
        printf("\nperforming pop...");
        printf("\n%d poped;", pop(&stk1));
        break;
    default:
        break;
    }
    return 0;
}

bool isempty(STACK *sp)
{
    if (!sp)
        return true;
    else
        return false;
}

bool isfull(STACK *sp)
{
    return sp ? true : false;
}

void push(STACK **sp, int data)
{
    if (*sp == NULL)
    {
        return;
    }
    STACK *temp;
    temp = (STACK *)calloc(1, sizeof(STACK));
    temp->data = data;
    temp->link = *sp;
    *sp = temp;
}

int pop(STACK **sp)
{
    if (*sp == NULL)
    {
        return;
    }
    STACK *temp;
    temp = *sp;
    *sp = temp->link;
    free(temp);
}
