#include <stdio.h>
#include <stdbool.h>
#define min(a, b) a < b ? a : b

struct Job
{
  char id;
  int dead;
  int profit;
};

void print_job_seq(struct Job arr[], int n)
{
  int result[n];
  bool slot[n];

  for (int i = 0; i < n; i++)
    slot[i] = false;

  // arrange in descending order.
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i].profit < arr[j].profit)
      {
        struct Job temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  // printf("After sorting: ");
  // for (int i = 0; i < n; i++)
  // {
  //   printf("%c ", arr[i].id);
  // }
  // printf("\n");

  for (int i = 0; i < n; i++)
  {
    for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
    {
      if (!slot[j])
      {
        slot[j] = true;
        result[j] = i;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (slot[i])
    {
      printf("%c ", arr[result[i]].id);
    }
  }
  printf("\n");
}

void main()
{
  struct Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("The Job sequence is: ");
  print_job_seq(arr, n);
}