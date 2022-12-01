#include "stdio.h"
int evenodd(int);

int main()
{
    int n,i;
    int evn=0,odd=0;
    printf(("en the range: "));
    scanf("%d",&n);
    for (i=1; i<=n; i++) {
        if (evenodd(i)==1) {
            evn++;
        }
        else 
            odd++;
    }
    printf("there are %d odd & %d even ons\n",evn,odd);
    return 0;
}

int evenodd(int no){
    if(no%2==1)
        return 1;
    else 
        return 0;    
}
