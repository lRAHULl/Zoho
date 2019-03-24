#include <stdio.h>

void note_counter(int amount)
{
  int notes[10] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  int counter[10];

  for (int i = 0; i < 10; i++)
  {
    counter[i] = 0;
    if (amount >= notes[i])
    {
      counter[i] = amount / notes[i];
      amount -= notes[i] * counter[i];
    }
  }
  printf("Currency count: \n");
  for (int i = 0; i < 10; i++)
  {
    if (counter[i])
    {
      printf("\t\t%d : %d\n", notes[i], counter[i]);
    }
  }
}

void main() 
{
  int amount = 24265;
  note_counter(amount);
}