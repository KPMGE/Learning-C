// we can allocate a vector within a fucntion and then returning it

#include <stdio.h>
#include <stdlib.h>

int *createArray(int size);
void readArray(int vector[], int size);
void displayArray(int vector[], int size);

int main(void) {
  int size;

  printf("enter vector's size: ");
  scanf("%d", &size);

  // allocating vector
  int *allocatedArray = createArray(size);

  // reading vector
  readArray(allocatedArray, size);

  // displaying vector
  displayArray(allocatedArray, size);

  // freeing memory allocated
  free(allocatedArray);

  return 0;
}

int *createArray(int size) {
  int *arr = (int *)malloc(size * sizeof(int));
  return arr;
}

void readArray(int vector[], int size) {
  printf("enter %d numbers:\n", size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &vector[i]);
  }
}

void displayArray(int vector[], int size) {
  printf("you vector is:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", vector[i]);
  }
}