#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool wildcard_pattern(char str[], char pattern[], int m, int n)
{
  if (n == 0)
    return m == 0;

  bool lookup[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      lookup[i][j] = false;

  lookup[0][0] = true;

  for (int j = 1; j < n; j++)
    if (pattern[j - 1] == '*')
      lookup[0][j] = lookup[0][j - 1];

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (pattern[j - 1] == '*')
        lookup[i][j] = lookup[i - 1][j] || lookup[i][j - 1];
      else if (pattern[j - 1] == '?' || pattern[j - 1] == str[i - 1])
        lookup[i][j] = lookup[i - 1][j - 1];
      else
        lookup[i][j] = false;
    }
  }
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
      printf("%d ", lookup[i][j]);
    printf("\n");
  }
  return lookup[m][n];
}

void main()
{
  char str[] = "abaaabab";
  char pattern[] = "*****ab***?b";
  if (wildcard_pattern(str, pattern, strlen(str), strlen(pattern)))
    printf("YES\n");
  else
    printf("NO\n");
}