#include <iostream>

using namespace std;

void swap(char *x, char *y)
{
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void findPermutations(char *s, int l, int r)
{
  int i;
  if (l == r)
    cout << s << endl;
  else
  {
    for (i = l; i < r; i++)
    {
      swap((s + l), (s + i));
      findPermutations(s, l + 1, r);
      swap((s + l), (s + i));
    }
  }
}

int main()
{
  char s[] = "ABC";
  int len;
  for (len = 0; s[len]; len++)
    ;
  findPermutations(s, 0, len - 1);
}