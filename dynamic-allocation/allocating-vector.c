// we can allocate a vector within a fucntion and then returning it

#include <stdio.h>
#include <stdlib.h>

int *createArray(int size);
void readArray(int array[], int size);
void displayArray(int array[], int size);

int main(void) {
  int size;

  printf("enter array's size: ");
  scanf("%d", &size);

  // allocating array
  int *allocatedArray = createArray(size);

  // reading array
  readArray(allocatedArray, size);

  // displaying array
  displayArray(allocatedArray, size);

  // freeing memory allocated
  free(allocatedArray);

  return 0;
}

int *createArray(int size) {
  int *arr = (int *)malloc(size * sizeof(int));
  return arr;
}

void readArray(int array[], int size) {
  printf("enter %d numbers:\n", size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
}

void displayArray(int array[], int size) {
  printf("you array is:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
}