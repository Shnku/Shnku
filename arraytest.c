#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int i, j, k;
    i = ++arr[1];
    j = arr[1]++;
    k = arr[i++];
    printf("%d %d %d", i, j, k);

    return 0;
}

// output..
/*
cd "/home/shanku/Documents/GitHub/Shnku/"&& gcc arraytest.c -o arraytest && "/home/shanku/Documents/GitHub/Shnku/"arraytest
4 3 4⏎
*/
