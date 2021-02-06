// Simpĺe program to display fibonacci sequence

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int number);
void displayFibonacciSequence(int size);

int main(void) {
  int size;

  printf("Enter size: ");
  scanf("%d", &size);

  displayFibonacciSequence(size);

  return 0;
}

int fibonacci(int number) {
  if (number == 0) {
    return 0;
  } else if (number == 1) {
    return 1;
  } else {
    return fibonacci(number - 1) + fibonacci(number - 2);
  }
}

void displayFibonacciSequence(int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", fibonacci(i));
  }
}