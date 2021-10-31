// a great use case for bitfields is for options.
#include <stdint.h>
#include <stdio.h>

#define OPTION_1 0x1     // 00000001
#define OPTION_2 0x2     // 00000010
#define OPTION_3 0x4     // 00000100
#define OPTION_4 0x8     // 00001000
#define OPTION_5 0x10    // 00010000
#define OPTION_6 0x20    // 00100000
#define OPTION_7 0x40    // 01000000
#define OPTION_8 0x80    // 10000000
#define ALL_OPTIONS 0xFF // 11111111

void display(uint8_t options);

int main(int argc, char *argv[]) {

  // here, when using the | operator we're enabling the right byte
  // in this case, we can easily enable as many options as we want.
  printf("Options 1, 3 and 5 selected:\n");
  display(OPTION_1 | OPTION_3 | OPTION_5);

  // we can define define custom macros to enable some options.
  printf("\nAll options selected:\n");
  display(ALL_OPTIONS);

  return 0;
}

void display(uint8_t options) {
  if (options & OPTION_1) {
    printf("Option 1 selected\n");
  }

  if (options & OPTION_2) {
    printf("Option 2 selected\n");
  }

  if (options & OPTION_3) {
    printf("Option 3 selected\n");
  }

  if (options & OPTION_4) {
    printf("Option 4 selected\n");
  }

  if (options & OPTION_5) {
    printf("Option 5 selected\n");
  }

  if (options & OPTION_6) {
    printf("Option 6 selected\n");
  }

  if (options & OPTION_7) {
    printf("Option 7 selected\n");
  }

  if (options & OPTION_8) {
    printf("Option 8 selected\n");
  }
}
