// simple recursive program for greatest common divisor 

#include <stdio.h>

int mdc(int p, int q) {
  if (q == 0) {
    return p;
  }
  return mdc(q, p%q);
}

int main(void) {
  int a, b;

  printf("enter two numbers:\n");
  scanf("%d %d", &a, &b);
  printf("MDC: %d\n", mdc(a, b));

  return 0;
}
