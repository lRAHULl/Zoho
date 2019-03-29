#include <iostream>

using namespace std;

int countDown(int num)
{
  if (num <= 0)
  {
    cout << "All Done\n";
    return 0;
  }
  cout << num << endl;
  num--;
  countDown(num);
}

int main()
{
  int num = 6;
  countDown(num);
}