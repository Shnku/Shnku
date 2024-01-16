#include <stdio.h>
typedef struct fcfs
{
    int pid;
    int arri_time;
    int brust_time;
    int complete_time;
    int wait_time;
    int turn_arr_time;
} Process;

int main()
{
    int n;
    float avg_tat = 0, avg_wt = 0;
    printf("\nen no of process: ");
    scanf("%d", &n);
    Process proc[n];

    for (int i = 0; i < n; i++)
    {
        printf("enter pid + AT + BT :: ");
        scanf("%d", &proc[i].pid);
        scanf("%d", &proc[i].arri_time);
        scanf("%d", &proc[i].brust_time);
    }

    // calculate wt then tat..
    // TAT = CT - BT ...
    // WT = TAT - BT ...
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        proc[i].complete_time = temp + proc[i].brust_time;
        proc[i].turn_arr_time = proc[i].complete_time - proc[i].arri_time;
        proc[i].wait_time = proc[i].turn_arr_time - proc[i].brust_time;
        avg_tat += proc[i].turn_arr_time;
        avg_wt += proc[i].wait_time;
        temp = proc[i].complete_time;
    }
    avg_tat /= n;
    avg_wt /= n;

    printf("\n___diaplaying stats..__\n");
    printf("\nPROC\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("\np%d\t%d\t%d\t%d\t%d\t%d", proc[i].pid, proc[i].arri_time, proc[i].brust_time, proc[i].complete_time,
               proc[i].turn_arr_time, proc[i].wait_time);
    }
    printf("\n\nAvg TAT: %f", avg_tat);
    printf("\nAvg_WT: %f", avg_wt);
    return 0;
}

/*

en no of process: 4
enter pid + AT + BT :: 0 0 10
enter pid + AT + BT :: 1 1 6
enter pid + AT + BT :: 2 3 2
enter pid + AT + BT :: 3 5 4

___diaplaying stats..__

PROC    AT      BT      CT      TAT     WT

p0      0       10      10      10      0
p1      1       6       16      15      9
p2      3       2       18      15      13
p3      5       4       22      17      13⏎

Avg TAT: 14.250000
Avg_WT: 8.750000
*/
