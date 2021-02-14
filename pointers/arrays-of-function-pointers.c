// we can use an array made of function pointes

#include <stdio.h>
#include <stdlib.h>

typedef int (*matematicOperation)(int, int);
matematicOperation operations[128] = {NULL};

void setOperations();
int sum(int num1, int num2);
int subtract(int num1, int num2);
int multi(int num1, int num2);
int doOperation(char operation, int num1, int num2);

int main(void) {
  int num1, num2;

  printf("enter two integer numbers: ");
  scanf("%d %d", &num1, &num2);

  // setting operations
  setOperations();

  printf("the sum of %d and %d is %d\n", num1, num2, doOperation('+', num1, num2));
  printf("the subraction of %d and %d is %d\n", num1, num2, doOperation('-', num1, num2));
  printf("the multiplication of %d and %d is %d", num1, num2, doOperation('*', num1, num2));

  return 0;
}

void setOperations() {
  operations['+'] = sum;
  operations['-'] = subtract;
  operations['*'] = multi;
}

int sum(int num1, int num2) {
  return num1 + num2;
}

int subtract(int num1, int num2) {
  return num1 - num2;
}

int multi(int num1, int num2) {
  return num1 * num2;
}

int doOperation(char operation, int num1, int num2) {
  matematicOperation someOperation = operations[operation];

  if (someOperation != NULL) {
    return someOperation(num1, num2);
  } else {
    printf("pointer NULL");
    exit(1);
  }
}