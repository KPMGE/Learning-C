// we use realloc function to modify the size of our allocated memory area

#include <stdio.h>
#include <stdlib.h>

void displayVector(int vector[], int size);

int main(void) {
  int *vector = (int *)malloc(3 * sizeof(int));

  vector[0] = 1;
  vector[1] = 32;
  vector[2] = 8;

  displayVector(vector, 3);

  // we need more space!
  vector = (int *)realloc(vector, 5);

  vector[3] = 6;
  vector[4] = 4;

  printf("\n\n");
  displayVector(vector, 5);

  return 0;
}

void displayVector(int vector[], int size) {
  printf("your vector is:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", vector[i]);
  }
}