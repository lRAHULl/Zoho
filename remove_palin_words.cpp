#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
  int i, j;
  int n = str.length();
  for (int i = 0; i < n / 2; i++)
  {
    if (str[i] != str[n - i - 1])
      return false;
  }
  return true;
}

string removePalindromes(string str)
{
  string word = "", result = "";
  str = str + ' ';
  int n = str.size();
  for (int i = 0; i < n; i++)
  {
    if (str[i] != ' ')
    {
      word = word + str[i];
    }
    else
    {
      if (!isPalindrome(word))
      {
        result = result + word + " ";
      }
      word = "";
    }
  }
  return result;
}

int main()
{
  string str = "Hello madam in malayalam";
  cout << removePalindromes(str) << endl;
  return 0;
}