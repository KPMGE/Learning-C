// calculating the value of pi with a serie

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double calculateSerie(int size);

int main(void) {
  int size;

  printf("Enter a size to serie: ");
  scanf("%d", &size);

  double pi = sqrt(6 * calculateSerie(size));

  printf("the value of pi is: %.20lf", pi);

  return 0;
}

double calculateSerie(int size) {
  double sumSerie = 0;

  for (int i = 1; i <= size; i++) {
    sumSerie += (1 / pow(i, 2));
  }
  return sumSerie;
}
