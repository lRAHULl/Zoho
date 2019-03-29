#include <iostream>

using namespace std;

int x[] = {0, 0, 1, -1, 1, -1, 1, -1};
int y[] = {1, -1, 0, 0, 1, -1, -1, 1};

bool searchMat(int mat[100][100], int row, int col, int pattern[100], int k)
{
  if (mat[row][col] != pattern[0])
  {
    return 0;
  }

  int startRow = row, startCol = col, dir;

  for (dir = 0; dir < 8; dir++)
  {
    int l, rd = row + x[dir], cd = col + y[dir];
    for (l = 1; l < k; l++)
    {
      if (rd >= row || rd < 0 || cd >= col || cd < 0)
      {
        break;
      }
      if (mat[rd][cd] != pattern[l])
      {
        break;
      }

      rd += x[dir], cd += y[dir];
    }

    if (k == l)
    {
      cout << "\nYES";
      cout << "\n\nStart Index: " << startRow << " " << startCol;
      cout << "\n  End Index: " << rd << " " << cd;
      return 1;
    }
  }
  return 0;
}

int patternSearch(int mat[100][100], int r, int c, int pattern[100], int k)
{
  int row, col, flag = 0;
  for (row = 0; row < r; row++)
  {
    for (col = 0; col < c; col++)
    {
      if (searchMat(mat, row, col, pattern, k))
      {
        flag = 1;
        cout << "Index: " << row << " " << col;
      }
    }
  }
  if (!flag)
  {
    cout << "\nNO";
    return 0;
  }
}

int main()
{
  int r, c, mat[100][100], pattern[100], k, i, j;

  cout << "Enter the no. of rows and columns: ";
  cin >> r >> c;
  cout << "Enter the matrix: \n";
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < c; j++)
    {
      cin >> mat[i][j];
    }
  }

  cout << "Enter the pattern size: ";
  cin >> k;
  cout << "\nEnter the pattern: ";
  for (i = 0; i < k; i++)
    cin >> pattern[i];

  patternSearch(mat, r, c, pattern, k);
}