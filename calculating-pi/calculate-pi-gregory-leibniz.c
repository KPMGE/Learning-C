// Calculating pi with Gregory-Leibniz series

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

double calculateSerie(int size);

int main(void) {
  int size;

  printf("Enter size to serie: ");
  scanf("%d", &size);

  double pi = calculateSerie(size);

  printf("The value of pi is: %.20lf", pi);

  return 0;
}

double calculateSerie(int size) {
  double sumSerie = 0;
  int logicVariable = TRUE;

  for (int k = 1; k < size; k += 2) {
    if (logicVariable) {
      sumSerie += 4.00 / k;
      logicVariable = FALSE;
    } else {
      sumSerie -= 4.00 / k;
      logicVariable = TRUE;
    }
  }

  return sumSerie;
}