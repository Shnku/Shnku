#include <stdio.h>
typedef struct srtf
{
    int pid;
    int at, bt;
    int ct, wt, tat;
} PROCESS;

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
        pc[i].pid = i;
        scanf("%d", &pc[i].at);
        scanf("%d", &pc[i].bt);
    }

    return 0;
}
