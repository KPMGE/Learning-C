#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef struct TYPED(matrix) TYPED(Matrix_t);

TYPED(Matrix_t*) TYPED(createMatrix) (unsigned int rows, unsigned int cols);
TYPE TYPED(getValueMatrix) (TYPED(Matrix_t *) matrix, unsigned int row, unsigned int col);
TYPE TYPED(getAmountRows) (TYPED(Matrix_t *) matrix);
TYPE TYPED(getAmountColumns) (TYPED(Matrix_t *) matrix);
void TYPED(setValueToMatrix) (TYPED(Matrix_t *) matrix, unsigned int row, unsigned int col, TYPE value);
void TYPED(fillMatrix) (TYPED(Matrix_t *) matrix, TYPE value);
void TYPED(displayMatrix) (TYPED(Matrix_t *) matrix);
TYPED(Matrix_t*) TYPED(multiplicateMatrix) (TYPED(Matrix_t *) matrix1, TYPED(Matrix_t *) matrix2);
void TYPED(freeMatrix) (TYPED(Matrix_t *) matrix);

#endif