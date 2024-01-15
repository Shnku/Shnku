#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *link;
} node;

typedef struct queue
{
    node *front;
    node *rear;
} Que;

int get_input(char *s);
int isEmpty(Que *ptr);
void init_Q(Que *q);
void enq(Que *q, int val);
int deq(Que *q);
void display(Que q);

int main()
{
    Que q1;
    int choice, val;

    printf("\n||__this is the Que system__||");
    printf("\n1) for enqueue...");
    printf("\n2) for dequeue...");
    printf("\n3) display Que...");
    while (1)
    {
        printf("\nEn yer choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            val = get_input("valu data: ");
            enq(&q1, val);
            break;
        case 2:
            val = deq(&q1);
            printf("\n%d dequeue...", val);
            break;
        case 3:
            if (q1.front->val==0)
            {
                printf("empty");
                break;
            }
            printf("\nthe Que is :: ");
            display(q1);
            break;
        default:
            break;
        }
    }
    return 0;
}

int get_input(char *s)
{
    int n;
    printf("\nen the %s", s);
    scanf("%d", &n);
    return n;
}

void init_Q(Que *q)
{
    q->front = q->rear = NULL;
}

void enq(Que *ptr, int value)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->val = value;
    temp->link = NULL;
    if (ptr->front == NULL)
    {
        ptr->front = temp;
        ptr->rear = temp;
    }
    else
    {
        (ptr->rear)->link = temp;
        ptr->rear = temp;
    }
}

int isEmpty(Que *ptr)
{
    if (ptr->front == NULL)
        return 1;
    else
        return 0;
}

int deq(Que *ptr)
{
    node *temp;
    int i;
    if (isEmpty(ptr))
    {
        return 0;
    }
    else
    {
        temp = ptr->front;
        ptr->front = ptr->front->link;
        i = temp->val;
        free(temp);
        return i;
    }
}

// void display(Que q1)
// {
//     if (q1.front == q1.rear)
//         printf("%d - ", q1.front->val);
//     while (q1.front != q1.rear)
//     {
//         printf("%d - ", q1.front->val);
//         q1.front = q1.front->link;
//     }
// }

void display(Que q1)
{
    while (q1.front)
    {
        printf("%d - ", q1.front->val);
        q1.front = q1.front->link;
    }
}

/*

*/
