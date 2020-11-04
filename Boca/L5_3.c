// Exercise: L5_3
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int size, i, currentDifference, greaterDifference = 0, boolVar = 0, peer, greater = 0;

  scanf("%d", &size);

  int heights[size];

  if (size == 1)
  {
    printf("IMPOSSIVEL");
    return 0;
  }

  scanf("%d", &heights[0]);
  for (i = 1; i < size; i++)
  {
    scanf("%d", &heights[i]);

    currentDifference = fabs(heights[i] - heights[i - 1]);

    if (heights[i] == heights[i - 1])
      boolVar++;

    if (currentDifference > greaterDifference)
    {
      greaterDifference = currentDifference;
      peer = i;
      greater++;
    }
  }

  if (boolVar != 0)
  {
    for (i = 1; i < size; i++)
      printf(" (%d %d)", i - 1, i);
  }
  else if (greater > 1)
  {
    for (i = 1; i < size; i++)
    {
      if (fabs(heights[i] - heights[i - 1]) == greaterDifference)
        printf(" (%d %d)", i - 1, i);
    }
  }
  else
    printf(" (%d %d)", peer - 1, peer);

  return 0;
}