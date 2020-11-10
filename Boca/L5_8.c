// Exercise: L5_8
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

void swapEvenAndOdd(int vector[], int qtd);
void displayVector(int vector[], int qtd);
int isOdd(int number);

int main(void) {
  int n, i;

  scanf("%d", &n);

  int vector[n];

  for (i = 0; i < n; i++) {
    scanf("%d", &vector[i]);
  }

  swapEvenAndOdd(vector, n);

  return 0;
}

int isOdd(int number){
  return (number % 2 != 0);
}

void swapEvenAndOdd(int vector[], int qtd) {
  int i, aux;

  for (i = 0; i < qtd; i++) {
    if (isOdd(i)) {
      aux = vector[i - 1];
      vector[i - 1] = vector[i];
      vector[i] = aux;
    }
  }

  displayVector(vector, qtd);
}

void displayVector(int vector[], int qtd) {
  int i;
  printf("{");
  for (i = 0; i < qtd; i++){
    if (i != 0)
      printf(", ");

    printf("%d", vector[i]);
  }
  printf("}");
}