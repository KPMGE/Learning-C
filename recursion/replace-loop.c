#include <stdio.h>

// function that displays number as a loop
int loop(int number) {
  if (number == 0) {
    printf("0");
    return 0;
  } else {
    printf("%d\n", number);
    return loop(number - 1);
  }
}

int main(void) {
  int n;

  printf("enter a number: ");
  scanf("%d", &n);

  loop(n);

  return 0;
}
