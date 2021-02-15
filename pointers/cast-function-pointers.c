// we can cast function pointers to another function pointers

#include <stdio.h>
#include <stdlib.h>

// creating function pointer that accepts an integer as parameter and returns an integer
typedef int (*fptrOneParameter)(int);
// creating function pointer that accepts an two integers as parameter and returns an integer
typedef int (*fptrTwoParameters)(int, int);


int sumTen(int number);
int sumNumbers(int number1, int number2);

int main(void) {
  // creating pointer functions
  fptrOneParameter functionOneParameter;
  fptrTwoParameters functionTwoParameters;

  functionOneParameter = sumTen;
  functionTwoParameters = (fptrTwoParameters)sumNumbers;

  printf("the sum of 1 + 1 is: %d", functionTwoParameters(1, 1));

  return 0;
}

int sumTen(int number) {
  return number + 10;
}

int sumNumbers(int number1, int number2) {
  return number1 + number2;
}