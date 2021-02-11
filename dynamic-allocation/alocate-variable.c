// simplest sample of memory allocation

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // allocating variable
  int *variable = (int *)malloc(sizeof(int));

  *variable = 200;
  printf("value: %d", *variable);

  // freeing memory
  free(variable);

  return 0;
}