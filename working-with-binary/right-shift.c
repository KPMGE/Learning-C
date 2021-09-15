#include <stdio.h>

int main(void) {
  int a = 10;

  // NOTE: a >> n is equivalent to a / 2^n
  printf("a = %d \t a >> 1 = %d\n", a, a >> 1);
  printf("a = %d \t a >> 2 = %d\n", a, a >> 2);
  printf("a = %d \t a >> 3 = %d\n", a, a >> 3);

  return 0;
}
