// when we sum or subtract an integer from a pointer, that is made by the value of sizeof(dataType)
// array without index is the address of the fist array memory place

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int array[] = {1, 43, 6, 60, 4};

  printf("the value of *(array + 1) is: %d\n", *(array + 1));
  printf("the value of array[1] is: %d", array[1]);

  return 0;
}