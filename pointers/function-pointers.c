// we can create pointers that points to functions

#include <stdio.h>
#include <stdlib.h>

typedef int (*ptrOperation)(int, int);
int sum(int num1, int num2);
int multi(int num1, int num2);

int main(void) {
  int num1 = 13, num2 = 4;
  // creating pointers to functions sum and multi
  ptrOperation fptrSum, fptrMulti;
  // assigning the address of sum and multi
  fptrSum = sum;
  fptrMulti = multi;

  printf("the sum of %d and %d is: %d\n", num1, num2, fptrSum(num1, num2));
  printf("the multiplication of %d and %d is: %d", num1, num2, fptrMulti(num1, num2));

  return 0;
}

int sum(int num1, int num2) {
  return num1 - num2;
}

int multi(int num1, int num2) {
  return num2 * num1;
}
