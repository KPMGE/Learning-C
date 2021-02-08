// simple recursive function to check if a number is prime
// author: Kevin Carvalho

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isPrime(int n, int divider);

int main(void) {
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  if (isPrime(n, 2)) {
    printf("true");
  } else {
    printf("false");
  }

  return 0;
}

int isPrime(int number, int divider) {
  if (number <= 2) {
    if (number == 2) {
      return TRUE;
    } else {
      return FALSE;
    }
  }
  if (number % divider == 0) {
    return FALSE;
  }
  if (divider * divider > number) {
    return TRUE;
  }
  return isPrime(number, divider + 1);
}