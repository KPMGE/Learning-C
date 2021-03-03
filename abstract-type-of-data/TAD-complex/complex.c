#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

struct complex {
  double real;
  double imag;
};

D_Complex_t* createComplex(double real, double imag) {
  D_Complex_t *complex = (D_Complex_t *)malloc(sizeof(D_Complex_t));

  complex->real = real;
  complex->imag = imag;

  return complex;
}

D_Complex_t* sumComplex(D_Complex_t *number1, D_Complex_t *number2) {
  D_Complex_t *complex = (D_Complex_t *)malloc(sizeof(D_Complex_t));

  complex->real = number1->real + number2->real;
  complex->imag = number1->imag + number2->imag;

  return complex;
}

D_Complex_t* subtractComplex(D_Complex_t *number1, D_Complex_t *number2) {
  D_Complex_t *complex = (D_Complex_t *)malloc(sizeof(D_Complex_t));

  complex->real = number1->real - number2->real;
  complex->imag = number1->imag - number2->imag;

  return complex;
}

D_Complex_t* subractComplexInto(D_Complex_t *number1, D_Complex_t *number2, D_Complex_t *number3) {
  number3->real = number1->real - number2->real;
  number3->imag = number1->imag - number2->imag;
}

double getRealField(D_Complex_t *number) {
  return number->real;
}

double getImaginaryField(D_Complex_t *number) {
  return number->imag;
}

void displayComplex(D_Complex_t *number) {
  printf("Your complex number is: ");

  if (number->imag > 0) {
    printf("%.3f + %.3fi", number->real, number->imag);
  } else if (number->imag < 0) {
    printf("%.3f - %.3fi", number->real, -(number->imag));
  } else {
    printf("%.3f", number->real);
  }
}

void accumulateComplex(D_Complex_t **number1, D_Complex_t *number2) {
  (*number1)->real = (*number1)->real + number2->real;
  (*number1)->imag = (*number1)->imag + number2->imag;
}

void freeComplex(D_Complex_t *number) {
  free(number);
}