#include <stdio.h>
#include <stdbool.h>

#define R 3
#define C 14

bool search_2D(char grid[R][C], int row, int col, char word[])
{
  int k, r, c;
  int x[] = {1,1,-1,-1,1,-1,0,0};
  int y[] = {1,-1,1,-1,0,0,1,-1};

  int len = 0;
  while (word[len])
    len++;

  if (grid[row][col] != word[0])
    return false;

  for (int dir = 0; dir < 8; dir++)
  {
    r = row + x[dir], c = col + y[dir];
    for (k = 1; k < len; k++)
    {
      if (r >= R || c >= C || r < 0 || c < 0)
        break;

      if (grid[r][c] != word[k])
        break;
      
      r += x[dir], c += y[dir];
    }
    if (k == len)
      return true;
  }
  return false;
}

void pattern_search(char grid[R][C], char word[])
{
  int flag = 0;
  for (int row = 0; row < R; row++)
  {
    for (int col = 0; col < C; col++)
    {
      if (search_2D(grid, row, col, word))
      {
        printf("The pattern found at (%d, %d).\n", row, col);
        flag = 1;
      }
    }
  }
  if (!flag)
  {
    printf("No Pattern Found.\n");
  }
}

void main()
{
  char grid[R][C] = {
      {'G', 'E', 'E', 'K', 'S', 'F', 'O', 'R', 'G', 'E', 'E', 'K', 'S'},
      {'G', 'E', 'E', 'K', 'S', 'Q', 'U', 'I', 'Z', 'G', 'E', 'E', 'K'},
      {'I', 'D', 'E', 'Q', 'A', 'P', 'R', 'A', 'C', 'T', 'I', 'C', 'E'}};

  pattern_search(grid, "GEEKS");
  printf("\n");
  pattern_search(grid, "EEE");
}