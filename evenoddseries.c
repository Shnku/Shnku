#include <stdio.h>
int evenodd(int);
// void disp_oddevn_array(int[],int[]);

int main()
{
    int n, i;
    int evn = 0, odd = 0;
    int evn_arr[100], odd_arr[100], size;
    printf(("en the range: "));
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        if (evenodd(i) == 1)
        {
            evn_arr[evn++] = i;
            // evn++;
        }
        else
        {
            odd_arr[odd++] = i;
            // odd++;
        }
    }
    printf("there are %d odd & %d even ons\n", evn, odd);

    // size= sizeof(evn_arr[100])+sizeof(odd_arr[100]);
    // printf("\nthe size is %d\n",size);
    // size= sizeof(evn_arr[100]+odd_arr[100]);
    // printf("the size is %d\n",size);
    // disp_oddevn_array(evn_arr,odd_arr);

    for (int i = 0, j = 0; i < evn && j < odd; i++, j++)
    {
        printf("%d\t%d\n", evn_arr[i], odd_arr[i]);
    }
    printf("..............................\n");
    return 0;
    exit(1);
}

int evenodd(int no)
{
    if (no % 2 == 1)
        return 1;
    else
        return 0;
}

// void disp_oddevn_array(int a[100],int b[100])
//{
//     // int size= sizeof(a[100])+sizeof(b[100]);//wrong because it returns size of int

//    for (int i=0; i<size; i++)
//    {
//        printf("%d\t%d\n",a[i],b[i]);
//    }

//}
