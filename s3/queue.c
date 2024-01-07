#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int val;
    struct queue *link;
} queue;

int get_input(char *s)
{
    int n;
    printf("\nen the %s", s);
    scanf("%d", &n);
    return n;
}

void enq(queue **rare, int val)
{
    if (*rare == NULL)
    {
        return;
    }
    queue *temp = (queue *)calloc(1, sizeof(queue));
    temp->val = val;
    temp->link = NULL;
    (*rare)->link = temp;
    *rare = temp;
}

int deq(queue **front)
{
    if (*front == NULL)
    {
        return;
    }
    queue *temp = *front;
    *front = temp->link;
    free(temp);
}

void display(queue *front, queue *rare)
{
    if (front == rare)
        printf("\nqueue is empty..");
    while (front != rare)
    {
        printf("%d - ", front->val);
        front = front->link;
    }
}

int main()
{
    queue *front, *rare;
    front = rare = NULL;

    int choice, val;
    printf("\n||__this is the queue system__||");
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
            val = get_input("valu data: ");
            enq(&front, val);
            break;
        case 2:
            printf("\nperforming dequeue...");
            deq(&rare);
            break;
        case 3:
            printf("\nthe queue is :: ");
            display(front, rare);
            break;
        default:
            break;
        }
    }

    return 0;
}
