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
    if (isempty(&p))
        p->front = p->rear = 0;
    else if (p->rear == MAX - 1)
    {
        for (int i = p->front; i <= p->rear; i++)
            p->val[i - p->front] = p->val[i];
        p->rear = p->rear - p->front + 1;
        p->front = 0;
    }
    else
        p->rear++;
    p->val[p->rear] = data;
}

int deq(Qarr *p)
{
    int temp;
    temp = p->val[p->front];
    if (p->front == p->rear)
        p->front = p->rear = -1;
    else
        p->front++;
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
