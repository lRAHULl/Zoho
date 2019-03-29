/*

Daily Coding Problem <founders@dailycodingproblem.com> Unsubscribe
27 Mar 2019, 22:01 (2 days ago)
to me

Good morning! Here's your coding interview problem for today.

This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, arr[1000], i, j, temp, res[1000], len = 0;
  map<int, int> nums;
  map<int, int>::iterator it;

  cout << "Length of the array: ";
  cin >> n;
  cout << "Enter the array: ";
  for (i = 0; i < n; i++)
    cin >> arr[i];

  for (i = 0; i < n; i++)
  {
    nums[arr[i]] ? nums[arr[i]] += 1 : nums[arr[i]] = 1;
  }

  for (it = nums.begin(); it != nums.end(); it++)
    cout << it->first << " " << it->second << endl;

  for (it = nums.begin(); it != nums.end(); it++)
  {
    if (it->first > 0)
    {
      res[len] = it->first;
    }
    else
    {
      res[len] = 0;
    }
    len++;
    // cout << len << endl;
  }
  if (res[0] > 1)
  {
    cout << 1 << endl;
    r eturn 0;
  }
  for (i = 0; i < len - 1; i++)
  {
    if (res[i] == 0 && res[i + 1] > 1)
    {
      // cout << "In If \n";
      cout << 1 << endl;
      return 0;
    }
    else if (res[i + 1] - res[i] > 1)
    {
      // cout << "In else If \n";
      cout << res[i] + 1 << endl;
      return 0;
    }
  }
  cout << res[len - 1] + 1 << endl;
  return 0;
}