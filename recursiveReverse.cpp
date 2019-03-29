#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void reverse(char *c)
{
  if (*c)
  {
    reverse(c + 1);
    cout << *c;
  }
}

int main()
{
  char str[] = "RAHUL";
  reverse(str);
  cout << endl;
  return 0;
}