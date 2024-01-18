#include <stdio.h>
typedef struct srtf
{
    int pid;
    int at, bt;
    int ct, wt, tat;
} PROCESS;

void sort(PROCESS p[], int count)
{
    PROCESS temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            printf("\n %d > %d ?", p[j].bt, p[j + 1].bt);
            if (p[j].bt > p[j + 1].bt)
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
        printf("- %d ", p[i].bt);
    }
}

void round_robin(PROCESS p[], int item, int time, int timeQ)
{
    int indx = 0;
    PROCESS readyQ[item];
    int rear = 0;

    readyQ[rear++] = p[indx++];
    for (int t = 1; t <= time; t++)
    {
        if (p[indx].at == t)
        {
            readyQ[rear] = p[indx];
            indx++, rear++;
        }
        // printf("\nTime: %d, Process: P%d, Remaining BT: %d", t, readyQ[0].pid, readyQ[0].bt);
        
        readyQ[0].bt--;
        if (readyQ[0].bt == 0)
        {
            p[readyQ[0].pid].ct = t;
            printf(" (Completed)");
            rear--;
        }
        else if ((t) % timeQ == 0)
        {
            PROCESS temp = readyQ[0];
            for (int i = 0; i < rear - 1; i++)
            {
                readyQ[i] = readyQ[i + 1];
            }
            readyQ[rear - 1] = temp;
        }
        // }
    }
}

int main()
{
    int n, time = 0, tq;
    float avg_tat = 0, avg_wt = 0;
    printf("\nen no of process: ");
    scanf("%d", &n);
    PROCESS pc[n];

    for (int t = 0; t < n; t++)
    {
        printf("enter AT + BT :: ");
        pc[t].pid = t;
        scanf("%d", &pc[t].at);
        scanf("%d", &pc[t].bt);
        time += pc[t].bt;
    }
    printf("enter time quantam: ");
    scanf("%d", &tq);
    round_robin(pc, n, time, tq);
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
    printf("\npc\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("\np%d\t%d\t%d\t%d\t%d\t%d", pc[i].pid, pc[i].at, pc[i].bt, pc[i].ct, pc[i].tat, pc[i].wt);
    }
    printf("\n\nAvg TAT: %f", avg_tat);
    printf("\nAvg_WT: %f", avg_wt);

    return 0;
}
