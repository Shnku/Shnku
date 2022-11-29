#include <stdio.h>
int main()
{
    int i,s,n;
    printf("en the nth term: ");
    scanf("%d",&n);

    for (i=1,s=0; i<=n; i+=1,s+=i) 
    {
        printf("i=%d\ts=%d\ts+i=%d\n",i,s,s+i);
    }
    printf("the sum is = %d\n",s);

    printf("...............................\n");
     for (i=1,s=0; i<=n; s+=i,i+=1) 
    {
        printf("i=%d\ts=%d\ts+i=%d\n",i,s,s+i);
    }
    printf("the sum is = %d\n",s);
}