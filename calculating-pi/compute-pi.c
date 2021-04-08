#include <stdio.h>
#include <stdio.h>
#include <math.h>

long double calculatePi(int num);

int main(void) {
  printf("Aproximations:");
  for (int i = 0; i < 10000; i++) {
    printf("%.66Lf\n", calculatePi(i));
  }

  return 0;
}

long double calculatePi(int num) {
  long double aprox = 0;

  for (int i = 0; i < num; i++) {
    aprox += 1.0/pow(16, i) * ((4.0 / (8*i + 1)) - (2.0/(8*i + 4)) - (1.0/(8*i + 5)) - (1.0/(8*i + 6)));
  }

  return aprox;
}

 
