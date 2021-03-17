#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#define TYPE float 

typedef struct matrix Matrix_t;

Matrix_t* createMatrix(unsigned int rows, unsigned int cols);
TYPE getValueMatrix(Matrix_t *matrix, unsigned int row, unsigned int col);
TYPE getAmountRows(Matrix_t *matrix);
TYPE getAmountColumns(Matrix_t *matrix);
void setVAlueToMatrix(Matrix_t *matrix, unsigned int row, unsigned int col, TYPE value);
void fillMatrix(Matrix_t *matrix, TYPE value);
void displayMatrix(Matrix_t *matrix);
Matrix_t* multiplicateMatrix(Matrix_t *matrix1, Matrix_t *matrix2);
void freeMatrix(Matrix_t *matrix);

#endif