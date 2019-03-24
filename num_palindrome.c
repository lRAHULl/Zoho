#include <stdio.h>

void main()
{
  int num, rem, result = 0, temp;

  printf("Enter a number to check if it is a palindrome: ");
  scanf("%d", &num);

  temp = num;

  while (num)
  {
    rem = num % 10;
    result = result * 10 + rem;
    num = num / 10;
    printf("\t%d %d %d\n", rem, num, result);
  }

  if (temp == result)
    printf("The Number is a palindrome\n");
  else
    printf("Not a Palindrome\n");
}