// we can pass const pointers to functions too

#include <stdio.h>
#include <stdlib.h>

void swapError(const int *youCannotModifyMe, int *normalVariable);

int main(void) {
  const int constVariable = 10;
  int someNumber = 34;

  swapError(&constVariable, &someNumber);

  return 0;
}

void swapError(const int *youCannotModifyMe, int *normalVariable) {
  int aux;

  // we can access the value of a const pointer
  printf("the value of const pointer is: %d", *youCannotModifyMe);

  // but we cannot modify its value
  aux = *normalVariable;
  *normalVariable = *youCannotModifyMe;
  // *youCannotModifyMe = aux; --> there will be an error! 
}