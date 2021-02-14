#include <stdio.h>
#include <stdlib.h>

void saferFree(void **pointer);

int main(void) {
  int var = (int *)malloc(2 * sizeof(int));

  // releasing memory
  saferFree(var);
  return 0;
}

void saferFree(void **pointer) {
  if (pointer != NULL && *pointer != NULL) {
    free(*pointer);
    *pointer = NULL;
  }
}