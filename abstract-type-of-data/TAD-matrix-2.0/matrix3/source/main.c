#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix-int.h"
#include "matrix-double.h"
#include "matrix-float.h"


int main(void) {
  // int matrices
  printf("Int matrices:\n\n");
  INT_Matrix_t* intMatrix1 = INT_createMatrix(3, 3);
  INT_Matrix_t* intMatrix2 = INT_createMatrix(3, 3);
  INT_Matrix_t* intMulti; 

  INT_fillMatrix(intMatrix1, 10);
  INT_fillMatrix(intMatrix2, 20);

  intMulti = INT_multiplicateMatrix(intMatrix1, intMatrix2);

  INT_displayMatrix(intMulti);
  INT_freeMatrix(intMatrix1);
  INT_freeMatrix(intMatrix2);
  INT_freeMatrix(intMulti);


  // float matrices
  printf("Float matrices:\n\n");
  FLOAT_Matrix_t* floatMatrix1 = FLOAT_createMatrix(3, 3);
  FLOAT_Matrix_t* floatMatrix2 = FLOAT_createMatrix(3, 3);
  FLOAT_Matrix_t* floatMulti; 

  FLOAT_fillMatrix(floatMatrix1, 10);
  FLOAT_fillMatrix(floatMatrix2, 20);

  floatMulti = FLOAT_multiplicateMatrix(floatMatrix1, floatMatrix2);

  FLOAT_displayMatrix(floatMulti);
  FLOAT_freeMatrix(floatMatrix1);
  FLOAT_freeMatrix(floatMatrix2);
  FLOAT_freeMatrix(floatMulti);


  // double matrices
  printf("Double matrices:\n\n");
  DOUBLE_Matrix_t* doubleMatrix1 = DOUBLE_createMatrix(3, 3);
  DOUBLE_Matrix_t* doubleMatrix2 = DOUBLE_createMatrix(3, 3);
  DOUBLE_Matrix_t* doubleMulti; 

  DOUBLE_fillMatrix(doubleMatrix1, 10);
  DOUBLE_fillMatrix(doubleMatrix2, 20);

  doubleMulti = DOUBLE_multiplicateMatrix(doubleMatrix1, doubleMatrix2);

  DOUBLE_displayMatrix(doubleMulti);
  DOUBLE_freeMatrix(doubleMatrix1);
  DOUBLE_freeMatrix(doubleMatrix2);
  DOUBLE_freeMatrix(doubleMulti);

  return 0;
}