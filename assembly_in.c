#include <stdio.h>

int main()
{
    int *c;
    __asm__("movl $10, %eax;"
            "movl $20, %ebx;"
            "addl %ebx, %eax;"
            "mov c, %ebx;");
    printf("\n%d", *c);
    return 0;
}
//! error...........
