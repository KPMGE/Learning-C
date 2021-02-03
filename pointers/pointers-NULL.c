#include <stdio.h>

int main(void) {
  int *pointer = NULL; // points for nothing

  // verifying if is NULL
  if (pointer) {
    printf("Is not NULL");
  } else {
    printf("Is NULL");
  }

  return 0;
}
