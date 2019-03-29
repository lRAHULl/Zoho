#include <stdio.h>

int prin() {
  return printf("HELLO\n");
}

int main()
{
  int a = 10;
  int *p;
  p = &a;
  printf("%d\n%u\n%d\n%u\n", a, p, *p, &a);
}