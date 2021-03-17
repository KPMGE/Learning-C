#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

#define TYPE float 
#define FORMAT "%f"

int main(void) {
  Matrix_t *matrix1 = createMatrix(2, 2);
  Matrix_t *matrix2 = createMatrix(2, 2);
  Matrix_t *multi;

  fillMatrix(matrix1, 10);
  fillMatrix(matrix2, 20);

  multi = multiplicateMatrix(matrix1, matrix2);
  displayMatrix(multi);

  freeMatrix(matrix1);
  freeMatrix(matrix2);
  return 0;
}