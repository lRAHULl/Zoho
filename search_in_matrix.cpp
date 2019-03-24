// #include <bits/stdc++.h>
// #include <string.h>
// using namespace std;
// #define R 3
// #define C 14

// bool search_2D(char grid[R][C], int row, int col, string word)
// {

//   int x[] = {1, -1, 1, -1, 1, -1, 0, 0};
//   int y[] = {1, 1, -1, -1, 0, 0, 1, -1};

//   if (grid[row][col] != word[0])
//     return false;

//   int len = 0;
//   while (word[len] != '\0')
//     len++;

//   for (int dir = 0; dir < 8; dir++)
//   {
//     int k;
//     int rd = row += x[dir];
//     int cd = col += y[dir];

//     for (k = 1; k < len; k++)
//     {
//       if (rd >= R || cd >= C || rd < 0 || cd < 0)
//       {
//         break;
//       }
//       if (grid[rd][cd] != word[k])
//       {
//         break;
//       }
//       rd += x[dir], cd += y[dir];
//     }
//     if (k == len)
//     {
//       return true;
//     }
//   }
//   return false;
// }

// void pattern_search(char grid[R][C], string word)
// {
//   for (int row = 0; row < R; row++)
//   {
//     for (int col = 0; col < C; col++)
//     {
//       if (search_2D(grid, row, col, word))
//       {
//         printf("The pattern found at: %d, %d\n", row, col);
//       }
//     }
//   }
// }

// int main()
// {
//   char grid[R][C] = {"GEEKSFORGEEKS", "GEEKSQUIZGEEK", "IDEQAPRACTICE"};
//   pattern_search(grid, "GEEKS");
//   return 0;
// }