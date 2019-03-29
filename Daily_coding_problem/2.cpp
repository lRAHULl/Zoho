/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
*/

#include <iostream>

using namespace std;

int main()
{
  int n, arr[100], prod = 1, res[100], i;
  cout << "Enter the length of an array: ";
  cin >> n;
  cout << "Enter the elements: ";
  for (i = 0; i < n; i++)
    cin >> arr[i];

  for (i = 0; i < n; i++)
    prod *= arr[i];

  for (i = 0; i < n; i++)
    res[i] = prod / arr[i];

  for (i = 0; i < n; i++)
    cout << res[i] << " ";
}