#include <stdio.h>

void main()
{
  int num,rem, var, binary = 0, i = 1;

  num = 31;

  var = num;

  while(num){
    rem = num % 2;
    num /= 2;
    binary += rem * i;
    i *= 10;
  }
  printf("%d \n", binary);
  
}