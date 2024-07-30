#include <stdio.h>
#include <stdlib.h>

void insertionsort(int *a, int n);
void disp(char *s, int a[], int n);
int comparisons = 0;

int main() {
    int A[] = {22, 88, 77, 11, 33, 55, 66, 44, 99, 1,
               2,  3,  4,  5,  6,  7,  8,  9,  10};
    int size = sizeof(A) / sizeof(A[0]);
    insertionsort(A, size);
    disp("after sort ", A, size);
    printf("no of comparisons = %d\n", comparisons);
    return 0;
}

// sorting function..
void insertionsort(int *a, int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && key < a[j]) {
            comparisons++;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// display function..........
void disp(char *s, int a[], int n) {
    printf("%s displaying..\n", s);
    for (int j = 0; j < n; j++) {
        printf("%d ", a[j]);
    }
    printf("\n");
}

// output..
/*
after sort  displaying..
1 2 3 4 5 6 7 8 9 10 11 22 33 44 55 66 77 88 99
no of comparisons = 104
*/