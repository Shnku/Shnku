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
            printf("\nperforming enqueue...");
            val = get_input("valu data: ");
            enq(&q1, val);
            break;
        case 2:
            printf("\nperforming dequeue...");
            deq(&q1);
            break;
        case 3:
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

void enq(Que *q1, int val)
{
    node *temp = (node *)calloc(1, sizeof(node));
    temp->val = val;
    temp->link = NULL;
}

int deq(Que *q)
{
    if (*front == NULL)
    {
        return;
    }
    Que *temp = *front;
    *front = temp->link;
    free(temp);
}

void display(Que q)
{
    if (front == q1.rear)
        printf("\nqueue is empty..");
    while (front != q1.rear)
    {
        printf("%d - ", front->val);
        front = front->link;
    }
}
