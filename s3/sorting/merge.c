#include <stdio.h>

int calls = 0;
void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);
void disp(char *s, int a[], int n);
int comparisons = 0;

// main function..........
int main() {
    // int A[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int A[] = {22, 88, 77, 11, 33, 55, 66, 44, 99, 1,
               2,  3,  4,  5,  6,  7,  8,  9,  10};
    int size = sizeof(A) / sizeof(A[0]);
    printf("%d is size ", size);
    disp("before", A, size);
    mergeSort(A, 0, size);
    disp("after", A, size);
    printf("no of comparisons = %d\n", comparisons);
    printf("no of calls = %d\n", calls);
}

// merge sort function...
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        comparisons++;
        calls++;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
// merge function..........
void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    i = k = 0, j = mid + 1;  // int bsize=high-low+1;
    int brr[high + 1];
    k = i = low;
    while (i <= mid && j <= high) {
        comparisons++;
        if (arr[i] < arr[j])
            brr[k++] = arr[i++];
        else
            brr[k++] = arr[j++];
    }
    while (j <= high) {
        comparisons++;
        brr[k++] = arr[j++];
    }
    while (i <= mid) {
        comparisons++;
        brr[k++] = arr[i++];
    }
    for (int m = low; m <= high; m++) arr[m] = brr[m];
}

// display function..........
void disp(char *s, int a[], int n) {
    printf("%s displaying..\n", s);
    for (int j = 0; j < n; j++) {
        printf("%d ", a[j]);
    }
    printf("\n");
}

/*output

before displaying..
2 8 7 1 3 5 6 4
after displaying..
1 2 3 4 5 6 8 7 //??why??

*/

// fixed..
/*
8 is size before displaying..
2 8 7 1 3 5 6 4
call no....1
call no....2
call no....3
call no....4
call no....5
call no....6
call no....7
call no....8
after displaying..
1 2 3 4 5 6 7 8
*/