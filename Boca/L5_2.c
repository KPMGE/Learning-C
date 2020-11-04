// Exercise: L5_2
// Author: Kevin carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int size, i, lessThan = 1, greaterThan = 1, equalThan = 1;

  scanf("%d", &size);

  int grades[size];

  scanf("%d", &grades[0]);
  for (i = 1; i < size; i++)
  {
    scanf("%d", &grades[i]);

    if (grades[i] == grades[i-1])
      equalThan++;
    if (grades[i] < grades[i-1])
      lessThan++;
    if (grades[i] > grades[i-1])
      greaterThan++;
  }

  if (size == 1 || equalThan == size)
    printf("CRESCENTE&DECRESCENTE");
  else if (lessThan == size)
    printf("DECRESCENTE");
  else if (greaterThan == size)
    printf("CRESCENTE");
  else
    printf("DESORDENADO");

  return 0;
}