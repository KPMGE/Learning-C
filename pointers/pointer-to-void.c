// we can points for a void, so that pointer will accept any other pointer type

#include <stdio.h>

int main(void) {
  int number = 10;
  int *pointerToNumber = &number;
  void *voidPointer = pointerToNumber;
  int *pointerToVoidToNumber = (int *) voidPointer;

  printf("number: %d\n", number);
  printf("value from pointer to number: %d\n", *pointerToNumber);
  printf("value from pointer to number to void: %d\n", *pointerToVoidToNumber);


  return 0;
}