#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int board[4][4];
int dirRow[] = {1, 0, -1, 0};
int dirCol[] = {0, 1, 0, -1};

pair<int, int> genUnoccupiedPair()
{
  int occupied = 1, row, col;
  while (occupied)
  {
    row = rand() % 4;
    col = rand() % 4;
    if (board[row][col] == 0)
      occupied = 0;
  }
  return make_pair(row, col);
}

// void addPiece()
// {
//   pair<int, int> pos = genUnoccupiedPair();
//   board[pos.first][pos.second] = 2;
// }

void newGame()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
      board[i][j] = 0;
  }
  pair<int, int> genPair = genUnoccupiedPair();
  board[genPair.first][genPair.second] = 2;
}

void printUI()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (board[i][j])
        cout << setw(4) << board[i][j];
      else
        cout << setw(4) << ".";
    }
    cout << endl;
  }
  cout << "\nN: New Game, Q: Quit, W: Up, S: Down, A: Left, D: Right.\nCommand: ";
}

bool canDoMove(int row, int col, int nextRow, int nextCol)
{
  if (nextRow < 0 || nextRow >= 4 || nextCol < 0 || nextCol >= 4 || (board[nextRow][nextCol] != board[row][col]))
    return false;
  return true;
}

void applyMove(int direction)
{
  int startRow = 0, startColumn = 0, rowStep = 1, columnStep = 1;
  if (direction == 0)
  {
    startRow = 3;
    rowStep = -1;
  }
  if (direction == 1)
  {
    startColumn = 3;
    columnStep = -1;
  }

  int movePossible = 0;
  for (int i = startRow; i >= 0 && i < 4; i += rowStep)
  {
    for (int j = startColumn; j >= 0 && j < 4; j += columnStep)
    {
      int nextI = i + dirRow[direction], nextJ = dirCol[direction];
      if (board[i][j] && canDoMove(i, j, nextI, nextJ))
      {
        board[nextI][nextJ] += board[i][j];
        board[i][j] = 0;
        movePossible = 1;
      }
    }
  }
  if (movePossible)
  {
    pair<int, int> genPair = genUnoccupiedPair();
    board[genPair.first][genPair.second] = 2;
  }
}

int main()
{

  char charToDim[128];

  charToDim['s'] = 0;
  charToDim['d'] = 1;
  charToDim['w'] = 2;
  charToDim['a'] = 3;

  while (true)
  {
    srand(time(0));
    newGame();
    printUI();
    char c;
    cin >> c;

    if (c == 'q')
      break;
    else if (c == 'n')
      newGame();
    else
    {
      int currentDir = charToDim[c];
      cout << currentDir << " ";
      // applyMove(currentDir);
    }
  }
}