#include <stdio.h>
typedef struct priority
{
    int pid;
    int at, bt, priority;
    int ct, wt, tat;
} PROCESS;

void sort(PROCESS p[], int start, int count)
{
    PROCESS waiting;
    for (int i = start; i < count - 1; i++)
    {
        for (int j = start; j < count - i; j++) // here c-i-1 changed..
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

    int temp = 0;

    sort(pc, 1, n);
    for (int i = 0; i < n; i++)
    {
        pc[i].ct = temp + pc[i].bt;
        pc[i].tat = pc[i].ct - pc[i].at;
        pc[i].wt = pc[i].tat - pc[i].bt;
        avg_tat += pc[i].tat;
        avg_wt += pc[i].wt;
        temp = pc[i].ct;
    }
    avg_tat /= n;
    avg_wt /= n;

    printf("\n___diaplaying stats..__\n");
    printf("\npc\tAT\tBT\tPRTY\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("\np%d\t%d\t%d\t%d\t%d\t%d\t%d", pc[i].pid, pc[i].at, pc[i].bt, pc[i].priority, pc[i].ct, pc[i].tat,
               pc[i].wt);
    }
    printf("\n\nAvg TAT: %f", avg_tat);
    printf("\nAvg_WT: %f", avg_wt);
}

/*

en no of process: 4
enter AT + BT + priority :: 0 10 5
enter AT + BT + priority :: 1 6 4
enter AT + BT + priority :: 3 2 2
enter AT + BT + priority :: 5 4 0

 6 > 2 ?
 6 > 4 ?
 2 > 4 ?
___diaplaying stats..__

pc      AT      BT      PRTY    CT      TAT     WT

p0      0       10      5       10      10      0
p3      5       4       0       14      9       5
p2      3       2       2       16      13      11
p1      1       6       4       22      21      15

Avg TAT: 13.250000
Avg_WT: 7.750000⏎
*/
