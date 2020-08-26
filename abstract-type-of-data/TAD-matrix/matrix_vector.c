//Program with functions for the TAD matrix, using a common vector to the matrix

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

struct matrix
{
    int row;
    int column;
    float* matrix;
};

Matrix* create_matrix(int row, int column)
{
    Matrix* matrixAllocated;
    matrixAllocated = (Matrix*) malloc(sizeof(Matrix));
    matrixAllocated->matrix = (float*) malloc(row * column * sizeof(float));
    matrixAllocated->row = row;
    matrixAllocated->column = column;

    return matrixAllocated;
}

void free_matrix(Matrix* matrix)
{
    free(matrix);
}

float acess_matrix(Matrix* matrix, int row, int column)
{
    return  matrix->matrix[row * matrix_columns(matrix) + column];
}

void assign_matrix(Matrix* matrix, int row, int column, float value)
{
    matrix->matrix[row * matrix_columns(matrix) + column] = value;
}

int matrix_rows(Matrix* matrix)
{
    return matrix->row;
}

int matrix_columns(Matrix* matrix)
{
    return matrix->column;
}
