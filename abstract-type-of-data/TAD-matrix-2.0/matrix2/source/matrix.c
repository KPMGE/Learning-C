#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

#define TYPE float 
#define FORMAT "%.2f "

struct matrix {
  unsigned int row;
  unsigned int col;
  TYPE **mat;
};

TYPED(Matrix_t*) TYPED(createMatrix)(unsigned int rows, unsigned int cols) {
  TYPED(Matrix_t) *allocatedMatrix = (TYPED(Matrix_t *)) malloc(sizeof(TYPED(Matrix_t)));

  if (allocatedMatrix == NULL) {
    printf("Insuficient space!");
    exit(1);
  }

  allocatedMatrix->mat = (TYPE **) malloc(rows * sizeof(TYPE));
  for (int i = 0; i < rows; i++) {
    allocatedMatrix->mat[i] = (TYPE *) malloc(cols * sizeof(TYPE));
  }

  allocatedMatrix->row = rows;
  allocatedMatrix->col = cols;

  return allocatedMatrix;
}

TYPE TYPED(getValueMatrix) (TYPED(Matrix_t *) matrix, unsigned int row, unsigned int col) {
  return matrix->mat[row][col];
}

TYPE TYPED(getAmountRows) (TYPED(Matrix_t *) matrix) {
  return matrix->row;
}

TYPE TYPED(getAmountColumns) (TYPED(Matrix_t *) matrix) {
  return matrix->col;
}

void TYPED(setValueToMatrix) (TYPED(Matrix_t *) matrix, unsigned int row, unsigned int col, TYPE value) {
  if (row >= matrix->row || col >= matrix->col) {
    printf("Invalid access!");
    exit(1);
  }

  matrix->mat[row][col] = value;
}

void TYPED(fillMatrix) (TYPED(Matrix_t *) matrix, TYPE value) {
  for (unsigned int i = 0; i < matrix->row; i++) {
    for (unsigned int j = 0; j < matrix->col; j++) {
      TYPED(setValueToMatrix) (matrix, i, j, value);
    }
  }
}

void TYPED(displayMatrix) (TYPED(Matrix_t *) matrix) {
  for (unsigned int i = 0; i < matrix->row; i++) {
    for (unsigned int j = 0; j < matrix->col; j++) {
      printf(FORMAT, TYPED(getValueMatrix) (matrix, i, j));
    }
    printf("\n");
  }
  printf("\n\n");
}

TYPED(Matrix_t*) TYPED(multiplicateMatrix) (TYPED(Matrix_t *) matrix1, TYPED(Matrix_t *) matrix2) {
  TYPE value;

  if (TYPED(getAmountRows) (matrix1) != TYPED(getAmountColumns) (matrix2)) {
    printf("You cannot do this operation!");
    exit(1);
  }

  TYPED(Matrix_t) *multi = TYPED(createMatrix) (TYPED(getAmountRows) (matrix1), TYPED(getAmountColumns) (matrix2));

  for (unsigned int i = 0; i < TYPED(getAmountRows) (multi); i++) {
    for (unsigned int j = 0; j < TYPED(getAmountColumns) (multi); j++) {
      value = 0;
      for (unsigned int k = 0; k < TYPED(getAmountColumns) (matrix1); k++) {
        value += TYPED(getValueMatrix) (matrix1, i, k) * TYPED(getValueMatrix) (matrix2, j, k);
      }
      TYPED(setValueToMatrix) (multi, i, j, value);
    }
  }

  return multi;
}

void TYPED(freeMatrix) (TYPED(Matrix_t *) matrix) {
  for (int i = 0; i < matrix->row; i++) {
    free(matrix->mat[i]);
  }
  free(matrix);
}
