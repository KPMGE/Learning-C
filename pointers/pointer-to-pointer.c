// when we pass a pointer to a function, it is passed by value, so if we can modify it, we must passt it as a pointer to pointer

#include <stdio.h>
#include <stdlib.h>

void allocateArray(int **array, int size, int number);

int main(void) {
  int size, *array = NULL;

  printf("enter array's size: ");
  scanf("%d", &size);

  allocateArray(&array, size, 19);

  printf("Your array is: \n");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  free(array);

  return 0;
}

void allocateArray(int **array, int size, int number) {
  *array = (int *)malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    *(*array + i) = number;
  }
}