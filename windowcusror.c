#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <termios.h>

// gotoxy() function definition
void gotoxy(int x, int y) { printf("%c[%d;%df", 0x1B, y, x); }

//void clrscr(void) { system("clear"); }

int main() {
  system("clear");
  int x = 10, y = 20;
  gotoxy(3, y);                 // move cursor position
  printf("Hello World!!!\n\n"); // print message
  return 0;
}
