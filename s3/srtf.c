#include <stdio.h>
#define MAX 10
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
        for (int j = 0; j < count - i - 1; j++) // here c-i-1 changed..
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
        printf("%d ", p[i].bt);
    }
}

void srtf(PROCESS p_list[], int no, int time)
{
    int indx = 0, flag = 0;
    PROCESS waitq[no];
    int rear = 0;

    waitq[rear++] = p_list[indx++];
    for (int t = 1; t <= time; t++)
    {
        waitq[0].bt--;
        printf("\n time= %d", t);
        if (p_list[indx].at == t)
        {
            disp(waitq, rear);
            waitq[rear] = p_list[indx];
            indx++, rear++;
            sort(waitq, rear);
            disp(waitq, rear);
        }
        if (waitq[0].bt == 0)
        {
            disp(waitq, rear);
            p_list[waitq[0].pid].ct = t;
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

//!fixed..
/*
en no of process: 4
enter AT + BT :: 0 10
enter AT + BT :: 1 6
enter AT + BT :: 3 2
enter AT + BT :: 5 4

 time= 1
 queue is ==== 9 
 9 > 6 ?
 queue is ==== 6 9 
 time= 2
 time= 3
 queue is ==== 4 9 
 4 > 9 ?
 9 > 2 ?
 4 > 2 ?
 queue is ==== 2 4 9 
 time= 4
 time= 5
 queue is ==== 0 4 9 
 0 > 4 ?
 4 > 9 ?
 9 > 4 ?
 0 > 4 ?
 4 > 4 ?
 0 > 4 ?
 queue is ==== 0 4 4 9 
 queue is ==== 0 4 4 9 
 queue is ==== 4 4 9 
 time= 6
 time= 7
 time= 8
 time= 9
 queue is ==== 0 4 9 
 queue is ==== 4 9 
 time= 10
 time= 11
 time= 12
 time= 13
 queue is ==== 0 9 
 queue is ==== 9 
 time= 14
 time= 15
 time= 16
 time= 17
 time= 18
 time= 19
 time= 20
 time= 21
 time= 22
 queue is ==== 0 
 queue is ==== 
___diaplaying stats..__

pc      AT      BT      CT      TAT     WT

p0      0       10      22      22      12
p1      1       6       9       8       2
p2      3       2       5       2       0
p3      5       4       13      8       4

Avg TAT: 10.000000
Avg_WT: 4.500000s
*/