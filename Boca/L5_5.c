// Exercise: L5_5
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int size, number, i;

  scanf("%d", &number);
  scanf("%d", &size);

  int vector[size];

  for (i = 0; i < size; i++)
  {
    scanf("%d", &vector[i]);

    if (vector[i] == number)
    {
      printf("RESP:%d", i);
      exit(0);
    }
  }

  printf("RESP:%d", size);

  return 0;
}