// Compute pi with a givem precision eps recursively
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <math.h>

long double calculatePiRecursive(int start, int end, float i);

int main(void) {
  printf("Aproximations:\n");
  for (int i =0; i < 10000; i++) {
    printf("%.66Lf\n", calculatePiRecursive(0, i, 0));
  }

  return 0;
}

long double calculatePiRecursive(int start, int end, float i) {
  // calculate approximation to pi
  long double aprox = 1.0/pow(16, i) * ((4.0 / (8*i + 1)) - (2.0/(8*i + 4)) - (1.0/(8*i + 5)) - (1.0/(8*i + 6)));

  // if approximation is less than eps
  if (start == end) {
    return aprox;
  } else {
    return aprox + calculatePiRecursive(start + 1, end, i+1);
  }
}
