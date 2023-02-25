#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("updating the git command: ");
    printf(".............................\n");

    system("git add --all");
    system("git commit -m //.//");
    system("git push");

    printf("\n\n.............................\n");
    printf("\n\ndone");
}
