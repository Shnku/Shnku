#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct queue_arr
{
    int val[MAX];
    int front;
    int rear;
} Qarr;

typedef enum
{
    false,
    true
} bool;

bool isempty(Qarr *p)
{
    if (p->front == -1 && p->rear == -1)
        return true;
    return false;
}

bool isfull(Qarr *p)
{
    if (p->front == 0 && p->rear == MAX - 1)
        return true;
    return false;
}

void init_Q(Qarr *p)
{
    (p)->front = (p)->rear = -1;
}

void enq(Qarr *p, int data)
{
    if (p->front == -1)
        p->rear = p->front = 0;
    else
        p->rear = (p->rear + 1) % MAX;
    p->val[p->rear] = data;
}

int deq(Qarr *p)
{
    int temp;
    temp = p->val[p->front];
    if (p->front == p->rear)
        p->front = p->rear = -1;
    else
        p->front = (p->front + 1) % MAX;
    return temp;
}

void display(Qarr q1)
{
    for (int i = q1.front; i <= q1.rear; i++)
    {
        printf(" %d - ", q1.val[i]);
    }
}

int main()
{
    int choice, val, dq;
    Qarr q1;
    printf("\n||__this is the queue system__||");
    init_Q(&q1);
    printf("\n1) for enqueue...");
    printf("\n2) for dequeue...");
    printf("\n3) display queue...");
    while (1)
    {
        printf("\nEn yer choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nperforming enqueue...");
            scanf("%d", &val);
            if (isfull(&q1))
            {
                printf("Queue is full ");
                break;
            }
            enq(&q1, val);
            break;
        case 2:
            printf("\nperforming dequeue...");
            if (isempty(&q1))
            {
                printf("Queue is empty..");
                break;
            }
            dq = deq(&q1);
            printf("%d out..", dq);
            break;
        case 3:
            printf("\nthe queue is :: ");
            display(q1);
            break;
        default:
            printf("quiting..");
            exit(1);
            break;
        }
    }
    return 0;
}

/*
||__this is the queue system__||
1) for enqueue...
2) for dequeue...
3) display queue...
En yer choice: 1

performing enqueue...10

En yer choice: 1

performing enqueue...20

En yer choice: 1

performing enqueue...30

En yer choice: 3

the queue is ::  10 -  20 -  30 -
En yer choice: 2

performing dequeue...10 out..
En yer choice: 2

performing dequeue...20 out..
En yer choice: 2

performing dequeue...30 out..
En yer choice: 2

performing dequeue...Queue is empty..
En yer choice: 3

the queue is ::  22080 -
En yer choice: 2

performing dequeue...Queue is empty..
En yer choice: 3

the queue is ::  22080 -
En yer choice: ^C⏎
*/
