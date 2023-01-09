#include <stdio.h>
#include <unistd.h>

int main() {
  int i, j, nth;
  printf("en the nth term row: ");
  scanf("%d", &nth);
  for (i = 1; i <= nth; i++) {
    for (j = nth; j >= i; j--) {
      printf("_");
      sleep(1);
    }
    for (int k = 1; k <= i; k++) {
      printf("*");
      sleep(1);
    }

    printf("\n");
    sleep(1);
  }
}