// quick sort program...
#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);
int partition(int *, int, int);
int rand_partition(int *, int, int);
// int (*fptr)(int *, int, int);
void quicksort(int *, int, int, int (*)(int *, int, int));
void disp(char *, int[], int);
int comparisons = 0, calls = 0;

int main() {
    int A[] = {22, 88, 77, 11, 33, 55, 66, 44, 99, 1,
               2,  3,  4,  5,  6,  7,  8,  9,  10};
    // int A[] = {2, 4, 56, 3, 23, 5, 67, 89, 12, 34, 90};
    // int A[] = {20, 18, 14, 13, 11, 10, 7, 5, 4, 3, 1};
    // int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int size = sizeof(A) / sizeof(A[0]), click = 0;
    disp("before", A, size);
    printf("entaer partioning scheme 1_normal 2_rand: ");
    scanf("%d", &click);
    switch (click) {
        case 1:
            quicksort(A, 0, size - 1, partition);
            break;
        case 2:
            quicksort(A, 0, size - 1, rand_partition);
            break;
        default:
            break;
    }
    disp("after", A, size);
    printf("no of comparisons = %d\n", comparisons);
    printf("no of calls = %d\n", calls);
}

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1;
    printf("\n%d pos = pivot is %d", high, pivot);
    for (int j = low; j <= high; j++) {
        if (A[j] < pivot) {
            i++;
            comparisons++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return i + 1;
}

int rand_partition(int A[], int low, int high) {
    int pos = low + rand() % (high - low + 1);
    // printf("\n%d pos = pivot is %d", pos, A[pos]);
    swap(&A[pos], &A[high]);
    return partition(A, low, high);
    // int pivot = A[pos]; //or = A[high];
    // printf("\nnow a[pos]=%d", A[pos]);
    // int i = low - 1;
    // for (int j = low; j <= high; j++) {
    //     if (A[j] < pivot) {
    //         i++;
    //         comparisons++;
    //         swap(&A[i], &A[j]);
    //     }
    // }
    // swap(&A[i + 1], &A[high]);
    // return i + 1;
}

void quicksort(int A[], int low, int high, int (*fptr)(int *, int, int)) {
    if (low < high) {
        comparisons++;
        calls++;
        // disp("inside", A, high + 1);
        int pivot = fptr(A, low, high);
        quicksort(A, low, pivot - 1, fptr);
        quicksort(A, pivot + 1, high, fptr);
    }
    // disp("out", A, high + 1);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void disp(char *s, int a[], int n) {
    printf("\n%s displaying..\n", s);
    for (int j = 0; j < n; j++) {
        printf("%d ", a[j]);
    }
    printf("\n");
}

/*output
before displaying..
22 88 77 11 33 55 66 44 99 1 2 3 4 5 6 7 8 9 10
entaer partioning scheme 1_normal 2_rand: 1

18 pos = pivot is 10
8 pos = pivot is 9
7 pos = pivot is 8
6 pos = pivot is 7
5 pos = pivot is 6
4 pos = pivot is 5
3 pos = pivot is 4
2 pos = pivot is 3
1 pos = pivot is 2
18 pos = pivot is 22
18 pos = pivot is 77
15 pos = pivot is 44
15 pos = pivot is 55
18 pos = pivot is 88after displaying..
1 2 3 4 5 6 7 8 9 10 11 22 33 44 55 66 77 88 99
no of comparisons = 65
no of calls = 14

//randomize..........
entaer partioning scheme 1_normal 2_rand: 2

18 pos = pivot is 77
15 pos = pivot is 44
12 pos = pivot is 7
5 pos = pivot is 2
5 pos = pivot is 4
5 pos = pivot is 6
12 pos = pivot is 8
12 pos = pivot is 22
10 pos = pivot is 9
10 pos = pivot is 10
15 pos = pivot is 55
18 pos = pivot is 99after displaying..
1 2 3 4 5 6 7 8 9 10 11 22 33 44 55 66 77 88 99
no of comparisons = 54
no of calls = 12
*/

// but result my not same all time..
/*
before displaying..
22 88 77 11 33 55 66 44 99
entaer partioning scheme 1_normal 2_rand: 1

8 pos = pivot is 99
7 pos = pivot is 44
2 pos = pivot is 33
1 pos = pivot is 11
7 pos = pivot is 88
6 pos = pivot is 66after displaying..
11 22 33 44 55 66 77 88 99
no of comparisons = 23
no of calls = 6

//randomized......
entaer partioning scheme 1_normal 2_rand: 2
8 pos = pivot is 88
6 pos = pivot is 55
3 pos = pivot is 11
3 pos = pivot is 33
6 pos = pivot is 77
after displaying..
11 22 33 44 55 66 77 88 99
no of comparisons = 18
no of calls = 5
*/
