#include <stdio.h>
#include <time.h>

void delay(int);

int main() {
  int i, j, nth;
  printf("en the nth term row: ");
  scanf("%d", &nth);
  for (i = 1; i <= nth; i++) {
    for (j = nth; j >= i; j--) {
      printf("_");
      delay(20);
      printf("");
    }
    delay(10);
    for (int k = 1; k <= i; k++) {
      printf("*");
      delay(30);
      printf("");
    }

    printf("\n");
    delay(10);
  }
}

void delay(int no_os_sec) {
  int milisec = no_os_sec * 1000;
  clock_t start = clock();
  while (clock() < start + milisec)
    ;
}