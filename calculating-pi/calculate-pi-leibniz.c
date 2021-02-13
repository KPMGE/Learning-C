// calculating the value of pi with a serie

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double calculateSerie(int size);

int main(void) {
  int size;

  printf("Enter size to serie: ");
  scanf("%d", &size);

  double pi = 4 * calculateSerie(size);

  printf("The value of pi is: %.20lf", pi);

  return 0;
}

double calculateSerie(int size) {
  double sumSerie = 0;

  for (int k = 1; k <= size; k++) {
    sumSerie += pow(-1, k + 1) / (2 * k - 1);
  }
  return sumSerie;
}