// Exercise: L5_4
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int size, a, b, qtdInsideInterval = 0, qtdOutsideInterval = 0;

  scanf("%d", &size);

  int i, vector[size];
  for (i = 0; i < size; i++)
    scanf("%d", &vector[i]);

  // reading interval
  scanf("%d", &a);
  scanf("%d", &b);

  // finding numbers inside interval
  for (a; a <= b; a++)
    for (i = 0; i < size; i++)
      if (vector[i] == a)
        qtdInsideInterval++;

  qtdOutsideInterval = size - qtdInsideInterval;
  printf("%d %d", qtdInsideInterval, qtdOutsideInterval);

  return 0;
}