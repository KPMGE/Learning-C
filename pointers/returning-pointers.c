// we can return pointers through functions

#include <stdio.h>
#include <stdlib.h>

int *allocateArray(int size);

int main(void) {
  // allocating array
  int *array = allocateArray(3);

  printf("entere 3 values: ");
  for (int i = 0; i < 3; i++) {
    scanf("%d", &array[i]);
  }

  printf("you typed values: %d %d %d", array[0], array[1], array[2]);

  // freeing allocated array
  free(array);

  return 0;
}

int *allocateArray(int size) {
  // allocating array
  int *arrayAllocated = (int *)malloc(size * sizeof(int));

  // filling it with 0s
  for (int i = 0; i < size; i++) {
    arrayAllocated[i] = 0;
  }

  return arrayAllocated;
}