#include <iostream>
#include <iomanip>

using namespace std;

int X[] = {0, 0, 1, -1, 1, -1, -1, 1};
int Y[] = {1, -1, 0, 0, 1, -1, 1, -1};

int countCells(int board[100][100], int x, int y, int n)
{
  int dir, xd, yd;
  int count = 0;
  xd = x, yd = y;
  for (dir = 0; dir < 8; dir++)
  {
    xd = x + X[dir], yd = y + Y[dir];
    while (xd < n && yd < n && xd >= 0 && yd >= 0 && board[xd][yd] == 0)
    {
      xd += X[dir], yd += Y[dir];
      count++;
    }
  }
  cout << "The number of steps the queen can move is: " << count;
  cout << endl;
  return count;
}

int main()
{
  int n, x, y, k, board[100][100], i, j;
  int kx, ky;
  cout << "Enter the size of the board: ";
  cin >> n;
  cout << "Enter the position of the queen: ";
  cin >> x >> y;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      board[i][j] = 0;

  board[x][y] = 10; // Pos. of the queen.
  // position of the obstacle.
  cout << "Enter the no. of obstacles: ";
  cin >> k;
  for (i = 0; i < k; i++)
  {
    cout << "Enter the position of the obstacles: ";
    cin >> kx >> ky;
    if (kx == x && ky == y)
    {
      cout << "The position has a queen\n";
      i--;
    }
    else
      board[kx][ky] = -10;
  }

  countCells(board, x, y, n);

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (board[i][j] == 0)
        cout << setw(4) << ".";
      else if (board[i][j] == 10)
        cout << setw(4) << "Q";
      else
        cout << setw(4) << "X";
    }
    cout << endl;
  }
}