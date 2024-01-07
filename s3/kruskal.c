#include <stdio.h>
#define MAX 10
void kruskal(int a, int arr[MAX][MAX]);
int find(int, int *);
int uni(int, int, int *);

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
    kruskal(n, mat);
    return 0;
}

void kruskal(int n, int arr[MAX][MAX])
{
    int ne = 0, min, parent[MAX], mincost = 0;
    int a, u;
    int b, v;
    while (ne < n)
    {
        for (int i = 1, min = 999; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (arr[i][j] < min)
                {
                    min = arr[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u, parent);
        v = find(v, parent);

        if (uni(u, v, parent))
        {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }

        arr[a][b] = arr[b][a] = 999;
    }
    printf("\nMinimum cost = %d\n", mincost);
}

int find(int i, int *parent)
{
    if (parent[i])     // change this to if insted while..
        i = parent[i]; // whart happns..
    return i;
}

int uni(int i, int j, int *parent)
{
    if (i != j)
    {
        parent[i] = j; // still seg fault if change i-j
        return 1;
    }
    return 0;
}

/*
some new issue
np of row and col= 7

Fill the matrix...
0 2 0 7 3 0 0
2 0 2 0 6 4 0
0 2 0 5 4 2 1
7 0 5 0 1 0 6
3 6 4 1 0 0 0
0 4 2 0 0 0 0
0 0 1 6 0 0 0
0 edge (7,2) =32767
1 edge (2,6) =32767
2 edge (3,4) =32767


*/

/*
output now
np of row and col= 7

Fill the matrix...
0 2 0 7 3 0 0
2 0 2 0 6 4 0
0 2 0 5 4 2 1
7 0 5 0 1 0 6
3 6 4 1 0 0 0
0 4 2 0 0 0 0
0 0 1 6 0 0 0
0 edge (4,7) =32767

*/
