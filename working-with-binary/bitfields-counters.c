// another great use-case for bitfields is for creating a struct with 
// options using as less memory as we can. That's so cool, cuz we can 
// use the minimum amount of bits to create the things we want.

#include <stdio.h>

// NOTE: the __attribute__((__packed__)) specifies that a variable or structure
// field has the smallest possible alignment. That is, one byte for a variable,
// and one bit for a field, unless you specify a larger value with the aligned
// attribute.

typedef struct __attribute__((__packed__)) counters {
  unsigned int litte : 2;  // using just 2 bits!
  unsigned int medium : 4; // using just 4 bits!
  unsigned int large : 6;  // using just 6 bits!
} Counters;

int main(int argc, char *argv[]) {
  Counters myCounter;

  // as we can see, just 2 bytes are used!
  printf("sizeof(myCounter) = %lu\n\n", sizeof(myCounter));

  printf("Counters: \n");
  for (int i = 0; i < 64; i++) {
    printf("little: %d\n", myCounter.litte);
    printf("medium: %d\n", myCounter.medium);
    printf("large: %d\n\n", myCounter.large);

    myCounter.litte++;
    myCounter.medium++;
    myCounter.large++;
  }

  return 0;
}
