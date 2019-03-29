#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <iterator>

using namespace std;

bool same(int arr1[], int arr2[], int n1, int n2)
{

  if (n1 != n2)
    return 0;

  
  map<int, int> counter1;
  map<int, int> counter2;
  // map<int, int> temp;
  map<int, int>::iterator it, t1, t2;
  int num, i, temp, count = 0;
  // cout << n1 << "\t" << n2 << endl;
  for (i = 0; i < n1; i++)
  {
    num = arr1[i];
    counter1[num] ? counter1[num] += 1 : counter1[num] = 1;
  }
  for (i = 0; i < n2; i++)
  {
    num = arr2[i];
    counter2[num] ? counter2[num] += 1 : counter2[num] = 1;
  }

  if (counter1.size() != counter2.size())
    return 0;
  else
  {
    for (it = counter1.begin(); it != counter1.end(); it++)
    {
      // cout << it->first << "\t" << it->second << endl;
      t1 = it;
      t2 = counter2.find(pow(it->first, 2));
      temp = t2->first;
      if (!temp)
        return 0;
      else if (it->second == t2->second)
      {
        cout << it->second << "\t" << t2->second << endl;
        count++;
      }
    }
  }
  if (count == counter1.size() && count == counter2.size())
    return 1;
  else
    return 0;
}

int main()
{
  int arr1[5] = {1, 2, 2, 2};
  int arr2[5] = {1, 4, 9, 4};
  int n1 = sizeof(arr1) / sizeof(arr1[0]) - 1, n2 = sizeof(arr2) / sizeof(arr2[0]) - 1;
  same(arr1, arr2, n1, n2) ? cout << "TRUE\n" : cout << "FALSE\n";
  return 0;
}