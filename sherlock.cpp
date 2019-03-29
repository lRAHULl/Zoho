#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n = 5;
  int arr[n+1] = {10, 1, 10, 1, 10};

  int a = 0, b = 0, newA, newB, curr, prev;
  for (int i = 1; i < n; i++)
  {
    curr = arr[i];
    prev = arr[i - 1];
    newA = max(a + abs(curr - prev), b + curr - 1);
    newB = max(a + abs(prev - 1), b);
    a = newA;
    b = newB; 
  }

  return 0;
}