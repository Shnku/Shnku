#include <stdio.h>
typedef struct srtf
{
    int pid;
    int at, bt;
    int ct, wt, tat;
} PROCESS;

void disp(PROCESS p[], int n)
{
    printf("\n___queue is______");
    for (int i = 0; i < n; i++)
    {
        printf("p%d ", p[i].pid);
    }
}

void shift(PROCESS readyQ[], int *rear)
{
    for (int i = 0; i < (*rear) - 1; i++)
    {
        readyQ[i] = readyQ[i + 1];
    }
    (*rear)--;
}

void round_robin(PROCESS p[], int item, int time, int timeQ)
{
    int indx = 0, timeQ2 = timeQ, flag = 0;
    PROCESS readyQ[item];
    int rear = 0, front = 0;

    readyQ[rear++] = p[indx++];
    timeQ2--;
    for (int t = 1; t <= time; t++)
    {
        readyQ[0].bt--;
        printf("\n(%d) Process=P%d,Remaining BT=%d", t, readyQ[0].pid, readyQ[0].bt);
        if (readyQ[0].bt == 0)
        {
            p[readyQ[0].pid].ct = t;
            printf(" (Completed)");
            disp(readyQ, rear);
            shift(readyQ, &rear); // as quantam end for <time quantam
            timeQ2 = 0, flag = 1; // if new proc insert
            disp(readyQ, rear);
        }
        if (timeQ2 == 0)
        {
            disp(readyQ, rear);
            printf("\nquantam end..");
            if (!flag) // check neded..
            {          // only do this when actually quantam end..
                PROCESS temp = readyQ[0];
                shift(readyQ, &rear);
                readyQ[rear++] = temp;
            }
            timeQ2 = timeQ;
            disp(readyQ, rear);
        }
        if (p[indx].at == t)
        {
            disp(readyQ, rear);
            readyQ[rear++] = p[indx++];
            disp(readyQ, rear);
        }
        timeQ2--, flag = 0; // changed..
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

// fixed..
/*
en no of process: 4
enter AT + BT :: 0 10
enter AT + BT :: 1 6
enter AT + BT :: 3 2
enter AT + BT :: 5 4
enter time quantam: 4

(1) Process=P0,Remaining BT=9
___queue is______p0
___queue is______p0 p1
(2) Process=P0,Remaining BT=8
(3) Process=P0,Remaining BT=7
___queue is______p0 p1
___queue is______p0 p1 p2
(4) Process=P0,Remaining BT=6
___queue is______p0 p1 p2
quantam end..
___queue is______p1 p2 p0
(5) Process=P1,Remaining BT=5
___queue is______p1 p2 p0
___queue is______p1 p2 p0 p3
(6) Process=P1,Remaining BT=4
(7) Process=P1,Remaining BT=3
(8) Process=P1,Remaining BT=2
___queue is______p1 p2 p0 p3
quantam end..
___queue is______p2 p0 p3 p1
(9) Process=P2,Remaining BT=1
(10) Process=P2,Remaining BT=0 (Completed)
___queue is______p2 p0 p3 p1
___queue is______p0 p3 p1
___queue is______p0 p3 p1
quantam end..
___queue is______p0 p3 p1
(11) Process=P0,Remaining BT=5
(12) Process=P0,Remaining BT=4
(13) Process=P0,Remaining BT=3
(14) Process=P0,Remaining BT=2
___queue is______p0 p3 p1
quantam end..
___queue is______p3 p1 p0
(15) Process=P3,Remaining BT=3
(16) Process=P3,Remaining BT=2
(17) Process=P3,Remaining BT=1
(18) Process=P3,Remaining BT=0 (Completed)
___queue is______p3 p1 p0
___queue is______p1 p0
___queue is______p1 p0
quantam end..
___queue is______p1 p0
(19) Process=P1,Remaining BT=1
(20) Process=P1,Remaining BT=0 (Completed)
___queue is______p1 p0
___queue is______p0
___queue is______p0
quantam end..
___queue is______p0
(21) Process=P0,Remaining BT=1
(22) Process=P0,Remaining BT=0 (Completed)
___queue is______p0
___queue is______
___queue is______
quantam end..
___queue is______
___diaplaying stats..__

pc      AT      BT      CT      TAT     WT

p0      0       10      22      22      12
p1      1       6       20      19      13
p2      3       2       10      7       5
p3      5       4       18      13      9

Avg TAT: 15.250000
Avg_WT: 9.750000⏎
*/
