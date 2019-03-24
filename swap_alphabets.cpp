#include <iostream>
#include <bits/stdc++.h>
#include <strings.h>

using namespace std;

bool isAlphabet(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void reverse(char str[])
{
  int l, r, n;
  char temp;
  n = strlen(str);
  l = 0;
  r = n - 1;

  while (l < r)
  {
    if (!isAlphabet(str[l]))
      l++;
    else if (!isAlphabet(str[r]))
      r--;
    else
    {
      temp = str[l];
      str[l] = str[r];
      str[r] = temp;
      l++;
      r--;
    }
  }
}

int main()
{
  char str[] = "a??bb:c";
  reverse(str);
  cout << str << endl;
  return 0;
}