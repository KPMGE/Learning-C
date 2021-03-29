
// simple program to get the greatest common divisor between two numbers
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

int mdc(int num1, int num2);

int main(void) {
  int num1, num2;

  printf("enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  printf("MDC = %d", mdc(num1, num2));

  return 0;
}

int mdc(int num1, int num2) {
  if (num2 == 0) {
    return num1;
  } else {
    return mdc(num2, num1 % num2);
  }
}
