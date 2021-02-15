// we can compare function pointers by using == or != operartors

#include <stdio.h>
#include <stdlib.h>

// creating function pointer that accepts an integer as parameter and returns an integer
typedef int (*fptr1)(int);

int sumTen(int number);

int main(void) {
  // creating pointers to functions
  fptr1 functionPointerToAnInteger, functionTest;

  // assigning values
  functionPointerToAnInteger = sumTen;
  functionTest = sumTen;

  // compare functions
  if (functionTest == functionPointerToAnInteger) {
    printf("function test equal to function to one integer!");
  } else {
    printf("Different");
  }

  return 0;
}

int sumTen(int number) {
  return number + 10;
}

int integerSum(float number1, float number2) {
  return number1 + number2;
}