// Exercise: L5_6
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i, size1, size2, qtdEqualItems = 0;

  // reading size 1
  scanf("%d", &size1);
  int vector1[size1];

  // reading first vector
  for (i = 0; i < size1; i++)
    scanf("%d", &vector1[i]);

  // reading size 2
  scanf("%d", &size2);
  int vector2[size2];

  // reading second vector
  for (i = 0; i < size2; i++)
    scanf("%d", &vector2[i]);


  // comparing vectors
  int j;
  for (i = 0; i < size2; i++)
  {
    for (j = 0; j < size1; j++)
    {
      if (vector2[i] == vector1[j])
        qtdEqualItems++;
    }
  }

  // comparing vectors
  if (qtdEqualItems == 0)
    printf("NENHUM");
  else if (qtdEqualItems == size1)
    printf("TODOS");
  else
    printf("PARCIAL");

  return 0;
}

