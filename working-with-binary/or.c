#include <stdio.h>

int main(void) {
  // we can use the bit operator or(|) to turn on a bit in a certain position
  // NOTE: the comparison will be 1 if one side is 1, therefore, we can shift 1 to the left n times
  // so, remember: 1 = 0000...0001, if you shift to left, the 1 will be on the position that you want
  // thus, if you use | the bit in that specific position will turn on. 

  int a = 2;  // 0000010

  printf("a = %d \t a | (1 << 2) = %d\n", a, a | (a << 2));
  printf("a = %d \t a | (1 << 3) = %d\n", a, a | (a << 3));
  printf("a = %d \t a | (1 << 4) = %d\n", a, a | (a << 4));

  return 0;
}
