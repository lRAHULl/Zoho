#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool validAnagram(string str1, string str2, int n1, int n2)
{
  if (n1 != n2)
    return 0;

  map<char, int> counter1;
  map<char, int> counter2;
  map<char, int> temp;

  map<char, int>::iterator it, t;

  int i, j, count = 0;

  char c;

  for (i = 0; i < n1; i++)
  {
    c = str1[i];
    counter1[c] ? counter1[c] += 1 : counter1[c] = 1;
  }
  for (i = 0; i < n2; i++)
  {
    c = str2[i];
    counter2[c] ? counter2[c] += 1 : counter2[c] = 1;
  }

  if (counter1.size() != counter2.size())
    return 0;
  else
  {
    for (it = counter1.begin(); it != counter1.end(); it++)
    {
      cout << it->first << "\t" << it->second << endl;
    }
    cout << endl;
    for (t = counter2.begin(); t != counter2.end(); t++)
    {
      cout << t->first << "\t" << t->second << endl;
    }
    cout << endl;

    if (counter1 == counter2)
      return 1;
  }
  return 0;
}

int main()
{
  string str1 = "anagram";
  string str2 = "nngaram";
  validAnagram(str1, str2, str1.length(), str2.length()) ? cout << "TRUE\n" : cout << "FALSE\n";
  return 0;
}