#include <stdio.h>
typedef struct sjf
{
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
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

int main()
{
    int n;
    float avg_tat = 0, avg_wt = 0;
    printf("\nen no of process: ");
    scanf("%d", &n);
    PROCESS pc[n];

    for (int i = 0; i < n; i++)
    {
        printf("enter AT + BT :: ");
        // scanf("%d", &pc[i].pid);
        pc[i].pid = i;
        scanf("%d", &pc[i].at);
        scanf("%d", &pc[i].bt);
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
    printf("\npc\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("\np%d\t%d\t%d\t%d\t%d\t%d", pc[i].pid, pc[i].at, pc[i].bt, pc[i].ct, pc[i].tat, pc[i].wt);
    }
    printf("\n\nAvg TAT: %f", avg_tat);
    printf("\nAvg_WT: %f", avg_wt);

    return 0;
}

/*
!wrong.......
en no of process: 4
enter AT + BT :: 0 10
enter AT + BT :: 1 6
enter AT + BT :: 3 2
enter AT + BT :: 5 4

___diaplaying stats..__

pc      AT      BT      CT      TAT     WT

p2      3       2       2       -1      -3
p3      5       4       6       1       -3
p1      1       6       12      11      5
p0      0       10      22      22      12

Avg TAT: 8.250000
Avg_WT: 2.750000⏎
*/

// right..
/*
en no of process: 4
enter AT + BT :: 0 10
enter AT + BT :: 1 6
enter AT + BT :: 3 2
enter AT + BT :: 5 4

 6 > 2 ?
 6 > 4 ?
 2 > 4 ?
___diaplaying stats..__

pc      AT      BT      CT      TAT     WT

p0      0       10      10      10      0
p2      3       2       12      9       7
p3      5       4       16      11      7
p1      1       6       22      21      15

Avg TAT: 12.750000
Avg_WT: 7.250000⏎
*/
