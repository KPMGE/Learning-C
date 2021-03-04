#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

int main(void) {
  D_Complex_t *number1, *number2, *sumNumbers, *subtractionNumbers, *multiNumbers, *divisionNumbers;

  number1 = createComplex(1, 4);
  number2 = createComplex(2, 3);

  // doing operations
  sumNumbers = sumComplex(number1, number2);
  subtractionNumbers = subtractComplex(number1, number2);
  multiNumbers = multiplicateComplex(number1, number2);
  divisionNumbers = divisionComplex(number1, number2);
  
  // displaying results
  printf("num1 + num2: ");
  displayComplex(sumNumbers);

  printf("\n\nnum1 - num2: ");
  displayComplex(subtractionNumbers);

  printf("\n\nnum1 * num2: ");
  displayComplex(multiNumbers);

  printf("\n\nnum1 / num2: ");
  displayComplex(divisionNumbers);

  printf("\n\naccumulated num1: ");
  accumulateComplex(&number1, number2);
  displayComplex(number1);

  // freeing  memory
  freeComplex(number1);
  freeComplex(number2);
  freeComplex(sumNumbers);
  free(subtractionNumbers);
  free(divisionNumbers);
  free(multiNumbers);

  return 0;
}