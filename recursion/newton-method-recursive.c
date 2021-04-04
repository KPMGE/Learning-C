// implementing newton's algorithm recursively
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <math.h>

double squareRootNewton(double num, double x0, double eps);

int main(void) {
  printf("aprox = %lf", squareRootNewton(2, 3, 0000.1));

  return 0;
}

double squareRootNewton(double num, double x0, double eps) {
  // calculate xn
  double xn = x0 - ((pow(x0, 2) - num) / (2 * x0));

  // if absolute value of xn -x0 is less than eps
  if (fabs(xn - x0) < eps) {
    return xn;
  } else {
    return squareRootNewton(num, xn, eps);
  }
}
