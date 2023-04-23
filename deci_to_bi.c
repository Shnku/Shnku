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

/*
 */
// problems...
/*
in reversing inplace  // not temp= arr[old]..
   for (new = 0; new < size / 2; new ++, old--)
    {
        temp = bi_arr[old];
        bi_arr[new] = bi_arr[old];
        bi_arr[old] = temp;
    }
but it cant  reverse prpperly
*/

//! implicit reverse is not possible....
// printf("\n");
// int i, j = size - 1;
// for (i = 0; i < size; i++)
// {
//     bi_arr[i] = bi_arr[j]; //! implicit reverse is not possible....
//     printf("\n=> biar[%d]=biarr[%d]=%d", i, j, bi_arr[j]);
//     j--;
// }
/*
 if you remove the malloc call and replace it with a pointer assignment, you will end up with a pointer that points to an unknown memory location.
 When you try to write to that location using bi_arr[size++] = rem;, you will be overwriting some unknown memory.
 Therefore, it is better to use malloc to allocate memory for the pointer.

 but here malloc allocate nothing...0 block ofmemory...reaaloc actually allocate 1 blok first ...the increases

You are correct that the initial malloc in the updated code allocates a block of size 0. However, this is not a problem because realloc can handle the case of a null pointer being passed to it, in which case it behaves like a malloc. In other words, when realloc is passed a null pointer, it simply allocates a new block of memory.

So, in the updated code, the first call to realloc is essentially behaving like a malloc, allocating a block of size sizeof(int) and returning a pointer to that block. Subsequent calls to realloc then increase the size of the block as necessary.
*/
