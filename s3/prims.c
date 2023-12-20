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
    int visited[MAX], x, y, min, mincost = 0, count = 1;
    for (int i = 0; i < nth; i++)
    {
        visited[i] = 0;
    }
    visited[1] = 1;
    while (nth > count)
    {
        min = 999;
        for (int i = 0; i < nth; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        x = i, y = j;
                    }
                    if (visited[x] == 0 || visited[y] == 0)
                    {
                        printf("\nEdge %d: (%d,%d) cost=%d", count++, x, y, min);
                        mincost += min;
                        visited[y] = 1;
                    }
                    cost[x][y] = cost[y][x] = 999;
                }
            }
        }
    }
}
