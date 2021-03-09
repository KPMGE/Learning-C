#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

struct matrix {
  float rows;
  float columns;
  float **innerMatrix;
};

Matrix* createMatrix(int rows, int columns) {
  Matrix *mat = (Matrix *)malloc(sizeof(Matrix));

  if (mat == NULL) {
    printf("Insuficient Space!");
    exit(1);
  }

  mat->innerMatrix = (float **) malloc(rows * sizeof(float *));
  for (int i = 0; i < rows; i++) {
    mat->innerMatrix[i] = (float *) malloc(columns * sizeof(float));
  }

  mat->rows = rows;
  mat->columns = columns;

  return mat;
}

int amountRows(Matrix *mat) {
  return mat->rows;
}

int amountColumns(Matrix *mat) {
  return mat->columns;
}

float getValueMatrix(Matrix *mat, int i, int j) {
  if (i < 0 || i >=mat->rows || j < 0 || j >= mat->columns) {
    printf("Invalid access!");
    exit(1);
  }

  return mat->innerMatrix[i][j];
}

void setValueMatrix(Matrix *mat, int i, int j, float value) {
  if (i < 0 || i >= mat->rows || j < 0 || j >= mat->columns) {
    printf("Invalid access!");
    exit(1);
  }

  mat->innerMatrix[i][j] = value;
}

void fillMatrix(Matrix *mat, float value) {
  for (int i = 0; i < mat->rows; i++) {
    for (int j = 0; j < mat->columns; j++) {
      mat->innerMatrix[i][j] = value;
    }
  }
}

void displayMatrix(Matrix *mat) {
  for (int i = 0; i < mat->rows; i++) {
    for (int j = 0; j < mat->columns; j++) {
      printf("%.2f ", mat->innerMatrix[i][j]);
    }
    printf("\n");
  }
}

Matrix* sumMatrices(Matrix *mat1, Matrix *mat2) {
  if ((mat1->rows != mat2->rows) || (mat1->columns != mat2->columns)) {
    printf("Invalid Sum!");
    exit(1);
  }
  
  Matrix *sum = createMatrix(mat1->rows, mat1->columns);

  for (int i = 0; i < mat1->rows; i++) {
    for (int j = 0; j < mat1->columns; j++) {
      sum->innerMatrix[i][j] = mat1->innerMatrix[i][j] + mat2->innerMatrix[i][j];
    }
  }

  return sum;
}

Matrix* subtractMatrices(Matrix *mat1, Matrix *mat2) {
  if ((mat1->rows != mat2->rows) || (mat1->columns != mat2->columns)) {
    printf("Invalid Sum!");
    exit(1);
  }
  
  Matrix *sub = createMatrix(mat1->rows, mat1->columns);

  for (int i = 0; i < mat1->rows; i++) {
    for (int j = 0; j < mat1->columns; j++) {
      sub->innerMatrix[i][j] = mat1->innerMatrix[i][j] - mat2->innerMatrix[i][j];
    }
  }

  return sub;
}

void freeMatrix(Matrix *mat) {
  for (int i = 0; i < mat->rows; i++) {
    free(mat->innerMatrix[i]);
  }
  free(mat->innerMatrix);
  free(mat);
}
