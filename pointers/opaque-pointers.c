// samples with opaque pointers
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

// generic function pointer to deal with each operation
typedef void* (*SUM_FUNCTION)(void*, void*);

// function to sum generic types
void* sumGeneric(void* val1, void* val2, SUM_FUNCTION sum);
// function to sum two integers
int* sumIntegers(int* val1, int* val2);
// function to sum two doubles
double* sumDoubles(double* val1, double* val2);

int main(void) {
  // sum ints
  int num1 = 8, num2 = 2;
  int* sumInt = sumGeneric(&num1, &num2, (SUM_FUNCTION)sumIntegers); 
  printf("Original numbers:\nnum1: %d\nnum2: %d\n", num1, num2);
  printf("sum: %d\n\n", *sumInt);

  // sum doubles
  double num3 = 5.35, num4 = 3.23;
  double* sumDouble = sumGeneric(&num3, &num4, (SUM_FUNCTION)sumDoubles);
  printf("Original numbers:\nnum3: %f\nnum4: %f\n", num3, num4);
  printf("sum doubles: %f\n", *sumDouble);

  // free allocated memory
  free(sumInt);
  free(sumDouble);

  return 0;
}

void* sumGeneric(void* val1, void* val2, SUM_FUNCTION sum) {
  return sum(val1, val2);
}

int* sumIntegers(int* val1, int* val2) {
  int* sum = malloc(sizeof(int));
  *sum = *val1 + *val2;
  return sum;
}

double* sumDoubles(double* val1, double* val2) {
  double* sum = malloc(sizeof(double));
  *sum = *val1 + *val2;
  return sum;
}
