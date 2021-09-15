#include <stdio.h>

int main(void) {
  // we can use the & operator in order to check if a number is or is not odd.
  // NOTE: the number 1 in binary is 00...01
  // NOTE: every odd number ends with a 1.
  // NOTE: every even number ends with a 0.

  int a = 23;

  // comparing the last bit, we can get if a number is odd
  if (a & 1) {
    printf("The number: %d is odd!", a);
  } else {
    printf("The number: %d isn't odd!", a);
  }

  // Also, we can check if a bit in a certain position is turned on. 
  // Again, we can use the properties of 1 in binary. If we shift 1 by n
  // positions, then compare with &, the comparison will be true only if that 
  // specific bit is true. because as you remember, all elements of 1 in binary are 0, 
  // except by that 1 in a certain position, so all comparisons will be false, then only the comparison
  // in that position will get you the right value.

  int c = 10; // 000...0101

  if (c & (1 << 3)) {
    printf("\nthe third bit of %d is on!", c);
  } else {
    printf("\nthe third bit of %d isn't on!", c);
  }

  return 0;
}
