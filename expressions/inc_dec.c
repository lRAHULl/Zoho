#include <stdio.h>

int prin() {
  return printf("HELLO\n");
}

int main()
{
  // int x = 0, y = 0;

  // x = y++ + y++ + y++; 
  // printf("x is %d, y is %d \n", x, y); // 3, 3

  // x = 0, y = 0;

  // x = ++y + ++y + y++;
  // printf("x is %d, y is %d \n", x, y); // 7, 3

  // x = 41, y = 43;

  // x = y++ + x++;
  // printf("x is %d, y is %d \n", x, y); //84, 44
  // y = ++y + ++x;
  // printf("x is %d, y is %d \n", x, y); // 85, 130
  printf("%f", prin());
  return 0;
}