// simple implementation of a map in C

#include <stdio.h>
#include <stdlib.h>

// defining pointer function
typedef int (*ptrSomeFunction)(int);

// defining map function
int* map(ptrSomeFunction function, int array[], int size);
int plusTen(int num);
void readArray(int array[], int size);
void displayArray(int array[], int size);

int main(void) {
  int size;

  printf("enter size: ");
  scanf("%d", &size);

  int arr[size];
  readArray(arr, size);

  // returnin an array allocated
  int *result = map(plusTen, arr, 3);

  displayArray(result, size);

  // releasing memory
  free(result);

  return 0;
}

int* map(ptrSomeFunction function, int array[], int size) {
  // allocate array
  int *finalArray = (int *)malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    finalArray[i] = function(array[i]);
  }

  return finalArray;
}

int plusTen(int num) {
  return num + 10;
}

void readArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
}

void displayArray(int array[], int size) {
  printf("outcome:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
}