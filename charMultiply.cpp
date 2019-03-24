#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void charMultiplier(string str)
{
  int n = str.length();
  // cout << n << endl;

  char c;
  int b;
  for (int i = 0; i < n; i++)
  {
    // cout << str[i] << endl;

    if (str[i] >= 'a' && str[i] <= 'z')
    {
      c = str[i];
      // cout << c << endl;
      if (str[i + 1] >= '0' && str[i + 1] <= '9')
      {
        i++;
        b = str[i] - 48;
        // cout << b << endl;
        if (str[i + 1] >= '0' && str[i + 1] <= '9')
        {
          i++;
          b = b * 10 + (str[i] - 48);
          // cout << b << endl;
        }
      }
    }
    for (int j = 0; j < b; j++)
    {
      cout << c;
    }
  }
  cout << endl;
}

int main()
{
  string str = "a99b20";
  charMultiplier(str);
  return 0;
}