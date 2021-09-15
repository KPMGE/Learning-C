#include <stdio.h>

int main(void) {
  // We can use the XOR operator (^) in order to toggle between a certain bit's state

  int a = 10; // 000...01010
  int b = a ^ (1 << 3);

  printf("a =  %d \t b = a ^ (1 << 3) = %d\n", a, b);
  printf("b =  %d \t a = b ^ (1 << 3) = %d\n", a, b ^ (1 << 3));

  return 0;
}
