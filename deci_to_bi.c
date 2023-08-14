#include <stdio.h>
#include <stdlib.h>
#define END -1

int *tconvert_bi(int);
void rev_array_inplace(int *, int);

int main()
{
    int decimal;
    printf("\nenter the no: ");
    scanf("%d", &decimal);

    int *binary = tconvert_bi(decimal);

    printf("\nthe binary eqv is: ");
    for (int i = 0; binary[i] != END; i++)
    {
        printf("%d", binary[i]);
    }

    free(binary);
    return 0;
}

int *tconvert_bi(int no)
{
    int *bi_arr = NULL;
    int rem, size = 0;
    bi_arr = malloc(sizeof(int) * 0);

    while (no > 0)
    {
        rem = no % 2;
        bi_arr = realloc(bi_arr, (size + 1) * sizeof(int));
        bi_arr[size++] = rem;
        no = no / 2;
    }
    rev_array_inplace(bi_arr, size);

    bi_arr[size] = END;
    return bi_arr;
}

void rev_array_inplace(int *arr, int size)
{
    int old = size - 1;
    int new = 0;
    for (; new < size / 2; new ++, old--)
    {
        int temp = arr[new];
        arr[new] = arr[old];
        arr[old] = temp;
    }
}


