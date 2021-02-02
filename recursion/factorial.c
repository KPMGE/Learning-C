#include <stdio.h>

int factorial(int number) {
  if (number == 1 || number == 0) {
    return 1;
  } else {
    return number * factorial(number - 1);
  }
}

int main(void) {
  int number;

  printf("Enter a number: ");
  scanf("%d", &number);

  printf("The factorial of %d is %d", number, factorial(number));
  return 0;
}
