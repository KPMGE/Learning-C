#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

int main(void) {
  D_Complex_t *number1, *number2, *sumNumbers;

  number1 = createComplex(1, 4);
  number2 = createComplex(2, 3);

  sumNumbers = sumComplex(number1, number2);

  printf("sum: \n");
  displayComplex(sumNumbers);

  printf("\n\naccumulated num1: \n");
  accumulateComplex(&number1, number2);
  displayComplex(number1);

  freeComplex(number1);
  freeComplex(number2);
  freeComplex(sumNumbers);

  return 0;
}