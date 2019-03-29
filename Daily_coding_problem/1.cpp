/*
Good morning! Here's your coding interview problem for today.

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

*/

#include <iostream>

using namespace std;

int main()
{
  int n, arr[1000], i, j, k;
  cout << "Enter the length of array: ";
  cin >> n;
  cout << "Enter the elements: ";
  for (i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Enter a number to check: ";
  cin >> k;

  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (arr[i] + arr[j] == k)
      {
        cout << "\nYES\n";
        return 1;
      }
    }
  }
  cout << "\nNO\n";
  return 0;
}