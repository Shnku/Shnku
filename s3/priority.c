#include <stdio.h>
typedef struct priority
{
    int pid;
    int at, bt, priority;
    int ct, wt, tat;
} PROCESS;



void sort(PROCESS p[], int count)
{
    PROCESS waiting;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++) // here c-i-1 changed..
        {
            printf("\n %d > %d ?", p[j].bt, p[j + 1].bt);
            if (p[j].priority > p[j + 1].priority)
            {
                waiting = p[j];
                p[j] = p[j + 1];
                p[j + 1] = waiting;
            }
        }
    }
}

int main()
{
    int n, maxtime = 0;
    float avg_tat = 0, avg_wt = 0;
    printf("\nen no of process: ");
    scanf("%d", &n);
    PROCESS pc[n];

    for (int i = 0; i < n; i++)
    {
        printf("enter AT + BT + priority :: ");
        pc[i].pid = i;
        scanf("%d", &pc[i].at);
        scanf("%d", &pc[i].bt);
        scanf("%d", &pc[i].priority);
        maxtime += pc[i].bt;
    }

    int time_arr[maxtime], indx = 0, indx2 = 0, tmp = 0;
    PROCESS waiting[n];
    for (int i = 0; i < maxtime; i++)
    {
        if (pc[indx].at == i)
        {
            waiting[indx] = pc[indx];
            // if (pc[indx].priority < waiting[indx2].priority)
            // indx2 = indx;
            indx++;
            sort(waiting, indx);
        }
        waiting[0].bt--;

        pc[i].ct = tmp + pc[i].bt;
        pc[i].tat = pc[i].ct - pc[i].at;
        pc[i].wt = pc[i].tat - pc[i].bt;
        avg_tat += pc[i].tat;
        avg_wt += pc[i].wt;
        tmp = pc[i].ct;
    }

    printf("\n___diaplaying stats..__\n");
    printf("\npc\tAT\tBT\tPRIORITY\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("\np%d\t%d\t%d\t%d\t%d\t%d\t%d", pc[i].pid, pc[i].at, pc[i].bt, pc[i].priority, pc[i].ct, pc[i].tat,
               pc[i].wt);
    }
    printf("\n\nAvg TAT: %f", avg_tat);
    printf("\nAvg_WT: %f", avg_wt);
}
