// Stack implementation in C
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include "../include/stack.h"

void addElementsIntoStack(const int *array, int size, Stack_t *stack);
void displayArray(const int *array, int size);

int main(void)  {
  const int arrayOfElements[] = {1, 33, 513, 64, 24};
  Stack_t *myStack = createEmptyStack(10);

  // adding arrayOfElements into myStack
  addElementsIntoStack(arrayOfElements, 5, myStack);

  // displaying original array 
  printf("Original array: ");
  displayArray(arrayOfElements, 5);

  // displaying stack
  printf("\nStack: ");
  displayStack(myStack);

  // displaying after popping 
  pop(myStack);
  printf("\nAfter popping...");
  printf("\nStack: ");
  displayStack(myStack);

  // displaying after popping 
  pop(myStack);
  printf("\nAfter popping again...");
  printf("\nStack: ");
  displayStack(myStack);

  // releasing stack
  freeStack(myStack);

  return 0;
}

void addElementsIntoStack(const int *array, int size, Stack_t *stack) {
  for (int i = 0; i < size; i++) {
    push(stack, array[i]);
  }
}

void displayArray(const int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
}
