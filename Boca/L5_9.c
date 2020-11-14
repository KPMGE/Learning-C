// Exercise: L5_9
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

void reverseVector(int *vector, int size);
void displayVector(int *vector, int size);

int main(void)
{
  int i, size;
  scanf("%d", &size);
  int vector[size];

  for (i = 0; i < size; i++)
    scanf("%d", &vector[i]);

  reverseVector(vector, size);

  return 0;
}

void displayVector(int *vector, int size)
{
  int i;
  printf("{");

  for (i = 0; i < size; i++)
  {
    if (i != 0)
      printf(", ");
    printf("%d", vector[i]);
  }
  
  printf("}");
}

void reverseVector(int *vector, int size)
{
  int i, j, reversedVector[size];

  for (j = (size - 1), i = 0; i < size; i++, j--)
  {
    reversedVector[j] = vector[i];
  }

  displayVector(reversedVector, size);
}
