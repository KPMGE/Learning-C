// we can use pointers with functions to in fact modify certain values

#include <stdio.h>
#include <stdlib.h>

void swap(int *variable1, int *variable2);

int main(void) {
  int a = 10, b = 45;

  printf("value of a: %d\n", a);
  printf("value of b: %d\n", b);

  // swapping
  swap(&a, &b);

  printf("\nafter swap...\n\n");
  printf("value of a: %d\n", a);
  printf("value of b: %d", b);

  return 0;
}

void swap(int *variable1, int *variable2) {
  int aux;
  aux = *variable1;
  *variable1 = *variable2;
  *variable2 = aux;
}