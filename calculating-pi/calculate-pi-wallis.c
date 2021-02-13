// calculating the value of pi with a serie

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double calculateSerie(int size);

int main(void) {
  int size;

  printf("Enter size to serie: ");
  scanf("%d", &size);

  double pi = 2 * calculateSerie(size);

  printf("The value of pi is: %.20lf", pi);

  return 0;
}

double calculateSerie(int size) {
  double sumSerie = 1;

  for (int k = 2; k < size; k++) {
    sumSerie *= (k / (double)(k - 1)) * (k / (double)(k + 1));
  }

  return sumSerie;
}
