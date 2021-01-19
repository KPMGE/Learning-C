#include <stdio.h>
#include <stdlib.h>

int factorial(int number);
void putSpaces(int amount);
void piramidFactorial(int size);

int main(void) {
  int size;
  printf("enter size: ");
  scanf("%d", &size);

  piramidFactorial(size);

  return 0;
}

int factorial(int number) {
  if (number == 0 || number == 1) {
    return 1;
  } else {
    return number * factorial(number - 1);
  }
}

void putSpaces(int amount) {
  for (int i = 0; i < amount; i++) {
    printf(" ");
  }
}

void piramidFactorial(int size) {
  for (int i = 1; i <= size; i++) {
    putSpaces(size - (i - 1));
    printf("%d ", factorial(i));
    for (int j = i - 1; j >= 1; j--) {
      printf("%d ", factorial(j));
    }
    printf("\n");
  }
}
