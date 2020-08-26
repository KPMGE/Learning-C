//Program with fuctions for the TAD matrix, using a vector of pointers

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

struct matrix
{
    int row;
    int column;
    float** matrix;
};

Matrix* create_matrix(int row, int column)
{
    int i;
    Matrix* matrixAllocated;
    matrixAllocated = (Matrix*) malloc(sizeof(Matrix));

    matrixAllocated->matrix = (float**) malloc(row * sizeof(float*));
    for(i = 0; i < row; i++)
        matrixAllocated->matrix[i] = (float*) malloc(column * sizeof(float));

    matrixAllocated->row = row;
    matrixAllocated->column = column;

    return matrixAllocated;
}

void free_matrix(Matrix* matrix)
{
    int i;

    for(i = 0; i < matrix_columns(matrix); i++)
        free(matrix->matrix[i]);
    free(matrix->matrix);
}

float acess_matrix(Matrix* matrix, int row, int column)
{
    return  matrix->matrix[row][column];
}

void assign_matrix(Matrix* matrix, int row, int column, float value)
{
    matrix->matrix[row][column] = value;
}

int matrix_rows(Matrix* matrix)
{
    return matrix->row;
}

int matrix_columns(Matrix* matrix)
{
    return matrix->column;
}
