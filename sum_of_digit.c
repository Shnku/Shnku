

#include <stdio.h>
int main()
{

  int a, s = 0, i = 0, r;
  //  printf("en the value");
  scanf("%d", &a);
  while (a != 0)
  {
    r = a % 10;
    s = s + r;
    a = a / 10;
  }
  printf("%d\n", s);
  return 0;
}
