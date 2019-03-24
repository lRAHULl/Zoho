/*
  The Number is said to be an armstrong number if the sum of power of length of the number is equal to the number.
*/

#include <stdio.h>
#include <math.h>

void main()
{
  int num, rem, t, temp, result = 0, count = 0;

  printf("Enter the number: ");
  scanf("%d", &num);

  temp = num;
  t = num;

  while (temp)
  {
    rem = temp % 10;
    count += 1;
    temp = temp / 10;
  }

  while (t)
  {
    rem = t % 10;
    result += pow(rem, count);
    t = t / 10;
  }
  if (result == num)
    printf("The number %d is an armstrong number.\n", num);
  else
    printf("%d is not an armstrong number.\n", num);
}