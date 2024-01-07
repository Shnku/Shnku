#include <stdio.h>
#define MAX 20
void prims(int a, int arr[MAX][MAX]);

int main()
{
    int mat[MAX][MAX], n;
    printf("\nnp of row and col= ");
    scanf("%d", &n);
    printf("\nFill the matrix...\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] == 0)
                mat[i][j] = 999;
        }
    }
    prims(n, mat);
    return 0;
}

void prims(int nth, int cost[MAX][MAX])
{
    int visited[MAX], min, mincost = 0, count = 1;
    for (int i = 0; i < nth; i++)
    {
        visited[i] = 0;
    }
    visited[0] = 1;
    while (nth > count)
    {
        min = 999;
        int x = 0, y = 0;
        for (int i = 0; i < nth; i++)
        {
            if (visited[i]) // only adjasent to visited vertices..
            {
                for (int j = 0; j < nth; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    // cost[i][j] checking not needed as they are already 999
                    {
                        min = cost[i][j];
                        x = i, y = j;
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, cost[x][y]);
        visited[y] = 1;
        mincost += min;
        count++;
    }
    printf("min cost= %d", mincost);
}

// nope it did wrong
/*

np of row and col= 7

Fill the matrix...
0 2 0 7 3 0 0
2 0 2 0 6 4 0
0 2 0 5 4 2 1
7 0 5 0 1 0 6
3 6 4 1 0 0 0
0 4 2 0 0 0 0
0 0 1 6 0 0 0
0 - 1 : 2
0 - 1 : 2
0 - 1 : 2
0 - 1 : 2
0 - 1 : 2
0 - 1 : 2
min cost= 12⏎
*/

// works after changing..
/*
?if visited 1 starting
np of row and col= 7

Fill the matrix...
0 2 0 7 3 0 0
2 0 2 0 6 4 0
0 2 0 5 4 2 1
7 0 5 0 1 0 6
3 6 4 1 0 0 0
0 4 2 0 0 0 0
0 0 1 6 0 0 0
1 - 0 : 2
1 - 2 : 2
2 - 6 : 1
2 - 5 : 2
0 - 4 : 3
4 - 3 : 1
min cost= 11⏎     */

//?if visited 0 starting
/*
np of row and col= 7

Fill the matrix...
0 2 0 7 3 0 0
2 0 2 0 6 4 0
0 2 0 5 4 2 1
7 0 5 0 1 0 6
3 6 4 1 0 0 0
0 4 2 0 0 0 0
0 0 1 6 0 0 0
0 - 1 : 2
1 - 2 : 2
2 - 6 : 1
2 - 5 : 2
0 - 4 : 3
4 - 3 : 1
min cost= 11*/
