#include <stdio.h>
#include <stdlib.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int);
int uni(int, int);

void main()
{
    printf("Kruskal's algorithm in C\n");
    printf("========================\n");

    printf("Enter the no. of vertices:\n");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v))
        {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
}

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }

    return 0;
}


/*
Kruskal's algorithm in C
========================
Enter the no. of vertices:
7

Enter the cost adjacency matrix:
0 2 0 7 3 0 0
2 0 2 0 6 4 0
0 2 0 5 4 2 1
7 0 5 0 1 0 6
3 6 4 1 0 0 0
0 4 2 0 0 0 0
0 0 1 6 0 0 0
The edges of Minimum Cost Spanning Tree are
1 edge (3,7) =1
2 edge (4,5) =1
3 edge (1,2) =2
4 edge (2,3) =2
5 edge (3,6) =2
6 edge (1,5) =3

Minimum cost = 11
*/
