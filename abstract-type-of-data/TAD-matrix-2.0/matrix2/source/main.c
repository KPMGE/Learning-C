#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

#define TYPE float 
#define FORMAT "%f"

int main(void) {
  TYPED(Matrix_t *) matrix1 = TYPED(createMatrix) (2, 2);
  TYPED(Matrix_t *) matrix2 = TYPED(createMatrix) (2, 2);
  TYPED(Matrix_t *) multi;

  TYPED(fillMatrix) (matrix1, 10);
  TYPED(fillMatrix) (matrix2, 20);

  multi = TYPED(multiplicateMatrix) (matrix1, matrix2);
  TYPED(displayMatrix) (multi);

  TYPED(freeMatrix) (matrix1);
  TYPED(freeMatrix) (matrix2);
  TYPED(freeMatrix) (multi);
  return 0;
}