#include <stdio.h>

void main() 
{
  int n;
  char str[n+1];

  printf("Enter the length of the string: ");
  scanf("%d", &n);
  printf("Enter the String: ");
  scanf("%s", str);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        printf("%c", str[i]);
      }
      else if(j == n - i - 1) 
      {
        printf("%c", str[n-i-1]);
      }
      else
      {
        printf(" ");
      }
      
    }
    printf("\n");
  }
  printf("%s", str);
}