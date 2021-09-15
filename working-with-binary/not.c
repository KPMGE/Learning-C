#include <stdio.h>

int main(void) {
  // NOTE: the result of ~number is (number + 1) * (-1)

  int n1 = 1;
  int n2 = 3;
  int n3 = 230;

  printf("n1 = %d \t ~(n1) = %d\n", n1, ~n1);
  printf("n2 = %d \t ~(n2) = %d\n", n2, ~n2);
  printf("n3 = %d \t ~(n3) = %d\n", n3, ~n3);

  return 0;
}
