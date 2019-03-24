#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  string binNum = "110001110", left = "", right = "", word = "", leftRes = "", rightRes = "", leftExtra = "", rightExtra = "";
  int leftLen = 0, rightLen = 0, i, j, flag = 0, leftRem = 0, rightRem = 0, count;

  map<string, char> binToHexMap;
  binToHexMap["0000"] = '0';
  binToHexMap["0001"] = '1';
  binToHexMap["0010"] = '2';
  binToHexMap["0011"] = '3';
  binToHexMap["0100"] = '4';
  binToHexMap["0101"] = '5';
  binToHexMap["0110"] = '6';
  binToHexMap["0111"] = '7';
  binToHexMap["1000"] = '8';
  binToHexMap["1001"] = '9';
  binToHexMap["1010"] = 'A';
  binToHexMap["1011"] = 'B';
  binToHexMap["1100"] = 'C';
  binToHexMap["1101"] = 'D';
  binToHexMap["1110"] = 'E';
  binToHexMap["1111"] = 'F';
  map<string, char>::iterator it;

  for (i = 0; binNum[i] != '\0'; i++)
  {
    if (binNum[i] != '.' && !flag)
    {
      left += binNum[i];
      leftLen++;
    }
    else if (binNum[i] == '.')
      flag = 1;
    else
    {
      right += binNum[i];
      rightLen++;
    }
  }

  leftRem += 4 - leftLen % 4;
  rightRem += 4 - rightLen % 4;

  for (i = 0; i < leftRem; i++)
  {
    leftExtra += '0';
    leftLen++;
  }
  left = leftExtra + left;

  if (rightLen)
  {
    for (i = 0; i < rightRem; i++)
    {
      rightExtra += '0';
      rightLen++;
    }
    right = right + rightExtra;
  }

  count = 0, i = 0;
  while (left[i])
  {
    if (count == 4)
    {
      count = 0;
      it = binToHexMap.find(word);
      leftRes += it->second;
      cout << word << "\t";
      word = "";
    }
    else
    {
      word += left[i];
      count++;
      i++;
    }
  }
  it = binToHexMap.find(word);
  leftRes += it->second;
  cout << word << "\t";
  word = "";

  if (rightLen)
  {
    count = 0, i = 0;
    while (right[i])
    {
      if (count == 4)
      {
        count = 0;
        it = binToHexMap.find(word);
        rightRes += it->second;
        cout << word << "\t";
        word = "";
      }
      else
      {
        word += right[i];
        count++;
        i++;
      }
    }
    it = binToHexMap.find(word);
    rightRes += it->second;
    cout << word << "\t";
  }

  if (rightLen)
    cout << leftRes << "." << rightRes << endl;
  else
  {
    cout << leftRes << endl;
  }
}