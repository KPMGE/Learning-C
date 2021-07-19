// string reversal with recursion

#include <stdio.h>

void reverseString(char *string);

int main(void) {
  char *name = "Kevin";

  reverseString(name);

  return 0;
}

void reverseString(char *string) {
  if (*string != '\0') {
    reverseString(string + 1);
    printf("%c", *string);
  }
} 
