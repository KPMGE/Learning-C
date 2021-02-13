// the function calloc looks like malloc, but it clean the memory at the same time

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // allocating by using calloc
  int *variable = (int *)calloc(1, sizeof(int));

  printf("the value of variable is: %d", *variable);

  // releasing memory
  free(variable);
  return 0;
}