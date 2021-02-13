// we use malloc function to allocate memory

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // allocating variable
  int *allocatedVariable = (int *)malloc(sizeof(int));

  *allocatedVariable = 10;
  printf("the value of allocated variable: %d", *allocatedVariable);

  // freeing variable
  free(allocatedVariable);
  return 0;
}