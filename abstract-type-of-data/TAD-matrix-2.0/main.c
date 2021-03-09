#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void) {
  Matrix *firstMatrix = createMatrix(2, 3);
  Matrix *secondMatrix = createMatrix(2, 3);

  fillMatrix(firstMatrix, 10);
  fillMatrix(secondMatrix, 2);

  Matrix *sum = sumMatrices(firstMatrix, secondMatrix);
  Matrix *sub = subtractMatrices(firstMatrix, secondMatrix);

  printf("sum:\n");
  displayMatrix(sum);
  printf("sub:\n");
  displayMatrix(sub);

  freeMatrix(firstMatrix);
  freeMatrix(secondMatrix);
  freeMatrix(sum);

  return 0;
}
