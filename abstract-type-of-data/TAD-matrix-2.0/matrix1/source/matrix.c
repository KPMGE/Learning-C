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

Matrix_t* createMatrix(unsigned int rows, unsigned int cols) {
  Matrix_t *allocatedMatrix = (Matrix_t *) malloc(sizeof(Matrix_t));

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

TYPE getValueMatrix(Matrix_t *matrix, unsigned int row, unsigned int col) {
  return matrix->mat[row][col];
}

TYPE getAmountRows(Matrix_t *matrix) {
  return matrix->row;
}

TYPE getAmountColumns(Matrix_t *matrix) {
  return matrix->col;
}

void setValueToMatrix(Matrix_t *matrix, unsigned int row, unsigned int col, TYPE value) {
  if (row >= matrix->row || col >= matrix->col) {
    printf("Invalid access!");
    exit(1);
  }

  matrix->mat[row][col] = value;
}

void fillMatrix(Matrix_t *matrix, TYPE value) {
  for (unsigned int i = 0; i < matrix->row; i++) {
    for (unsigned int j = 0; j < matrix->col; j++) {
      setValueToMatrix(matrix, i, j, value);
    }
  }
}

void displayMatrix(Matrix_t *matrix) {
  for (unsigned int i = 0; i < matrix->row; i++) {
    for (unsigned int j = 0; j < matrix->col; j++) {
      printf(FORMAT, getValueMatrix(matrix, i, j));
    }
    printf("\n");
  }
  printf("\n\n");
}

Matrix_t* multiplicateMatrix(Matrix_t *matrix1, Matrix_t *matrix2) {
  TYPE value;

  if (getAmountRows(matrix1) != getAmountColumns(matrix2)) {
    printf("You cannot do this operation!");
    exit(1);
  }

  Matrix_t *multi = createMatrix(getAmountRows(matrix1), getAmountColumns(matrix2));

  for (unsigned int i = 0; i < getAmountRows(multi); i++) {
    for (unsigned int j = 0; j < getAmountColumns(multi); j++) {
      value = 0;
      for (unsigned int k = 0; k < getAmountColumns(matrix1); k++) {
        value += getValueMatrix(matrix1, i, k) * getValueMatrix(matrix2, j, k);
      }
      setValueToMatrix(multi, i, j, value);
    }
  }

  return multi;
}

void freeMatrix(Matrix_t *matrix) {
  for (int i = 0; i < matrix->row; i++) {
    free(matrix->mat[i]);
  }
  free(matrix);
}
