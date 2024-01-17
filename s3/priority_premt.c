#include <stdio.h>
typedef struct srtf
{
    int pid;
    int at, bt, priority;
    int ct, wt, tat;
} PROCESS;

void sort(PROCESS p[], int count)
{
    PROCESS temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            printf("\n %d > %d ?", p[j].priority, p[j + 1].priority);
            if (p[j].priority > p[j + 1].priority)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void disp(PROCESS p[], int n)
{
    printf("\n queue is ==== ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p[i].bt);
    }
}

void priority(PROCESS p[], int size, int time)
{
    int indx = 0, flag = 0;
    PROCESS waitq[size];
    int rear = 0;

    waitq[rear++] = p[indx++];
    for (int t = 1; t <= time; t++)
    {
        waitq[0].bt--;
        printf("\n time= %d", t);
        if (p[indx].at == t)
        {
            disp(waitq, rear);
            waitq[rear] = p[indx];
            indx++, rear++;
            disp(waitq, rear);
            sort(waitq, rear);
        }
        if (waitq[0].bt == 0)
        {
            disp(waitq, rear);
            p[waitq[0].pid].ct = t;
            for (int i = 0; i < rear; i++)
            {
                waitq[i] = waitq[i + 1];
            }
            rear--;
            disp(waitq, rear);
        }
    }
}

int main()
{
    int n, time = 0;
    float avg_tat = 0, avg_wt = 0;
    printf("\nen no of process: ");
    scanf("%d", &n);
    PROCESS pc[n];

    for (int t = 0; t < n; t++)
    {
        printf("enter AT + BT + priority :: ");
        pc[t].pid = t;
        scanf("%d", &pc[t].at);
        scanf("%d", &pc[t].bt);
        scanf("%d", &pc[t].priority);
        time += pc[t].bt;
    }
    priority(pc, n, time);
    for (int i = 0; i < n; i++)
    {
        pc[i].tat = pc[i].ct - pc[i].at;
        pc[i].wt = pc[i].tat - pc[i].bt;
        avg_tat += pc[i].tat;
        avg_wt += pc[i].wt;
    }
    avg_tat /= n;
    avg_wt /= n;

    printf("\n___diaplaying stats..__\n");
    printf("\npc\tAT\tBT\tPRIORITY   CT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("\np%d\t%d\t%d\t%d\t%d\t%d\t%d", pc[i].pid, pc[i].at, pc[i].bt, pc[i].priority, pc[i].ct, pc[i].tat,
               pc[i].wt);
    }
    printf("\n\nAvg TAT: %f", avg_tat);
    printf("\nAvg_WT: %f", avg_wt);

    return 0;
}
