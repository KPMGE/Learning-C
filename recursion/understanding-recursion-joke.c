#include <stdio.h>

#define TRUE 1
#define FALSE 0

int understandingRecursion(int number) {
  if (number == 0) {
    printf("Oh, finally i understand recursion!");
    return TRUE;
  } else {
    printf("I don't understand it yet\n");
    return understandingRecursion(number - 1);
  }
}

int main(void) {
  int number;

  printf("Enter a number: ");
  scanf("%d", &number);

  understandingRecursion(number);

  return 0;
}
