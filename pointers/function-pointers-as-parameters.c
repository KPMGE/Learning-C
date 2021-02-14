// we can pass a function pointer as a parameter of another function an so, we can use it normally

#include <stdio.h>
#include <stdlib.h>

typedef int (*ptrOperation)(int, int);

int doOperation(ptrOperation operation, int num1, int num2);
int sum(int num1, int num2);
int subtract(int num1, int num2);

int main(void) {
  int value1, value2;

  ptrOperation fptrSum, fptrSub;
  fptrSum = sum;
  fptrSub = subtract;

  printf("enter two values: ");
  scanf("%d %d", &value1, &value2);

  printf("the sum of %d to %d is: %d\n", value1, value2, doOperation(fptrSum, value1, value2));
  printf("the subtraction of %d to %d is: %d", value1, value2, doOperation(fptrSub, value1, value2));

  return 0;
}

int doOperation(ptrOperation operation, int num1, int num2) {
  return operation(num1, num2);
}

int sum(int num1, int num2) {
  return num1 + num2;
}

int subtract(int num1, int num2) {
  return num1 - num2;
}
