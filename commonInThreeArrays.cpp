#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n1, n2, n3, len, i, p1, p2, p3;
  int arr1[1000], arr2[1000], arr3[1000], result[1000];

  cout << "Enter a length of three arrays: ";
  cin >> n1 >> n2 >> n3;

  cout << "Enter the length of array 1: ";
  for (i = 0; i < n1; i++)
    cin >> arr1[i];

  cout << "Enter the length of array 2: ";
  for (i = 0; i < n2; i++)
    cin >> arr2[i];

  cout << "Enter the length of array 3: ";
  for (i = 0; i < n3; i++)
    cin >> arr3[i];

  p1 = 0, p2 = 0, p3 = 0, len = 0;
  while (p1 < n1 && p2 < n2 && p3 < n3)
  {
    if (arr1[p1] == arr2[p2] && arr2[p2] == arr3[p3])
    {
      result[len] = arr1[p1];
      len++;
      p1++;
      p2++;
      p3++;
    }
    else if (arr1[p1] < arr2[p2])
    {
      p1++;
    }
    else if (arr2[p2] < arr3[p3])
    {
      p2++;
    }
    else
    {
      p3++;
    }
  }

  cout << "\nThe length of the result array is: " << len << endl;
  cout << "The common elements are: ";
  for (i = 0; i < len; i++)
    cout << result[i] << " ";
  cout << endl;
}