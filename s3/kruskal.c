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
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j, int *parent)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
