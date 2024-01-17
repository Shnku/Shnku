#include <stdio.h>
#define MAX 10
typedef struct srtf
{
    int pid;
    int at, bt;
    int ct, wt, tat;
} PROCESS;

void sort(PROCESS p[], int start, int count)
{
    PROCESS temp;
    for (int i = start; i < count - 1; i++)
    {
        for (int j = start; j < count - i; j++) // here c-i-1 changed..
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

void srtf(PROCESS p_list[], int no, int time)
{
    int indx = 0, flag = 0;
    PROCESS waitq[no];
    int rear = 0, front = 0;

    waitq[rear++] = p_list[indx++];
    for (int t = 1; t <= time; t++)
    {
        if (p_list[indx].at == t)
        {
            waitq[rear] = p_list[indx];
            indx++, rear++;
            sort(waitq, front, rear);
        }
        waitq[front].bt--;
        if (waitq[front].bt == 0)
        {
            p_list[waitq[front].pid].ct = t;
            front += 1;
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
        printf("enter AT + BT :: ");
        pc[t].pid = t;
        scanf("%d", &pc[t].at);
        scanf("%d", &pc[t].bt);
        time += pc[t].bt;
    }
    srtf(pc, n, time);
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

// out..
/*
en no of process: 4
enter AT + BT :: 0 10
enter AT + BT :: 1 6
enter AT + BT :: 3 2
enter AT + BT :: 5 4

 10 > 6 ?
 10 > 953040898 ?
 4 > 10 ?
 10 > 2 ?
 10 > 51113008 ?
 4 > 2 ?
 4 > 10 ?
 4 > 10 ?
 10 > 4 ?
 4 > 4 ?
___diaplaying stats..__

pc      AT      BT      CT      TAT     WT

p0      0       10      22      22      12
p1      1       6       8       7       1
p2      3       2       4       1       -1
p3      5       4       12      7       3

Avg TAT: 37.000000
Avg_WT: 15.000000⏎

*/
