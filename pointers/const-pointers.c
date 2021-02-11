// we can create const pointers 

#include <stdio.h>

int main(void) {
  int num = 10, num2 = 11;
  int const *pointer = &num;

  // we can modify the value of num, but we cannot modify value of pointer
  pointer = &num2;
  *pointer = 200; // error

  // const pointer to const varible
  const int num3 = 10;
  const int *pointer2j = &num3;

  // we cannot modify the value of num3
  pointer2 = &num2;
  *pointer2 = 39;

  return 0;
}