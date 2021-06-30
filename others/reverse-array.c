#include <stdio.h>
#include <stdlib.h>

void reverseArray(int **array, int size);
void displayArray(int *array, int size);

int main(void) {
  int *arr = (int*)malloc(5 * sizeof(int));

  for (int i = 0; i < 5; i++) {
    arr[i] = i + 1;
  }

  printf("Before: ");
  displayArray(arr, 5);

  reverseArray(&arr, 5);

  printf("\nAfter: ");
  displayArray(arr, 5);

  free(arr);

  return 0;
}

void reverseArray(int **array, int size) {
  int aux[size];

  for (int i = size -1, j = 0; i >= 0; i--, j++) {
    aux[j] = (*array)[i];
  }

  for (int i = 0; i < size; i++) {
    (*array)[i] = aux[i];
  }
}

void displayArray(int *array, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      printf("%d]", array[i]);
      break;
    }

    printf("%d, ", array[i]);
  }
}
