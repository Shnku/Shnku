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
    int indx = 0;
    PROCESS waitq[size];
    int rear = 0;

    waitq[rear++] = p[indx++];
    for (int t = 1; t <= time; t++)
    {
        waitq[0].bt--;
        printf("\n time= %d", t);
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
        if (p[indx].at == t)
        {
            disp(waitq, rear);
            waitq[rear] = p[indx];
            indx++, rear++;
            sort(waitq, rear);
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
    printf("\npc\tAT\tBT\tPRYT    CT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("\np%d\t%d\t%d\t%d\t%d\t%d\t%d", pc[i].pid, pc[i].at, pc[i].bt, pc[i].priority, pc[i].ct, pc[i].tat,
               pc[i].wt);
    }
    printf("\n\nAvg TAT: %f", avg_tat);
    printf("\nAvg_WT: %f", avg_wt);

    return 0;
}

/*

en no of process: 4
enter AT + BT + priority :: 0 10 5
enter AT + BT + priority :: 1 6 2
enter AT + BT + priority :: 3 2 0
enter AT + BT + priority :: 5 4 9

 time= 1
 queue is ==== 9
 5 > 2 ?
 queue is ==== 6 9
 time= 2
 time= 3
 queue is ==== 4 9
 2 > 5 ?
 5 > 0 ?
 2 > 0 ?
 queue is ==== 2 4 9
 time= 4
 time= 5
 queue is ==== 0 4 9
 0 > 2 ?
 2 > 5 ?
 5 > 9 ?
 0 > 2 ?
 2 > 5 ?
 0 > 2 ?
 queue is ==== 0 4 9 4
 queue is ==== 0 4 9 4
 queue is ==== 4 9 4
 time= 6
 time= 7
 time= 8
 time= 9
 queue is ==== 0 9 4
 queue is ==== 9 4
 time= 10
 time= 11
 time= 12
 time= 13
 time= 14
 time= 15
 time= 16
 time= 17
 time= 18
 queue is ==== 0 4
 queue is ==== 4
 time= 19
 time= 20
 time= 21
 time= 22
 queue is ==== 0
 queue is ====
___diaplaying stats..__

pc      AT      BT      PRYT    CT      TAT     WT

p0      0       10      5       18      18      8
p1      1       6       2       9       8       2
p2      3       2       0       5       2       0
p3      5       4       9       22      17      13

Avg TAT: 11.250000
Avg_WT: 5.750000⏎
*/

// problem when ascending order of priority/..
/*
n no of process: 4
enter AT + BT + priority :: 0 10 5
enter AT + BT + priority :: 1 6 4
enter AT + BT + priority :: 3 2 3
enter AT + BT + priority :: 5 4 1

 time= 1
 queue is ==== 9
 5 > 4 ?
 queue is ==== 6 9
 time= 2
 time= 3
 queue is ==== 4 9
 4 > 5 ?
 5 > 3 ?
 4 > 3 ?
 queue is ==== 2 4 9
 time= 4
 time= 5
 queue is ==== 0 4 9
 3 > 4 ?
 4 > 5 ?
 5 > 1 ?
 3 > 4 ?
 4 > 1 ?
 3 > 1 ?
 queue is ==== 4 0 4 9
 time= 6
 time= 7
 time= 8
 time= 9
 queue is ==== 0 0 4 9
 queue is ==== 0 4 9
 time= 10
 time= 11
 time= 12
 time= 13
 time= 14
 time= 15
 time= 16
 time= 17
 time= 18
 time= 19
 time= 20
 time= 21
 time= 22
___diaplaying stats..__

pc      AT      BT      PRYT    CT      TAT     WT

p0      0       10      5       262144  262144  262134
p1      1       6       4       0       -1      -7
p2      3       2       3       32768   32765   32763
p3      5       4       1       9       4       0

Avg TAT: 73728.000000
Avg_WT: 73722.500000⏎
*/
