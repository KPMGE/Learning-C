#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_bit_on(unsigned int number, int n);
void print_bits(unsigned int n);
void turn_on_bit(unsigned int *number, int n);
void turn_off_bit(unsigned int *number, int n);
void swap(int *a, int *b);
void turn_off_right_most_bit(unsigned int *number);
bool is_power_of_two(unsigned int number);

int main () {
  // check if the nth bit is turned on
  unsigned int a = 0x00ff;
  int c = 10, d = 15;

  printf("number: ");
  print_bits(a);
  printf("\nbit0: %s, bit28: %s\n", is_bit_on(a, 0) ? "on" : "off", is_bit_on(a, 28) ? "on" : "off");

  // turn on 20th bit
  turn_on_bit(&a, 20);
  printf("number: ");
  print_bits(a);
  printf("\nbit20: %s\n", is_bit_on(a, 20) ? "on" : "off");

  // turn off 2th bit
  turn_off_bit(&a, 2);
  printf("number: ");
  print_bits(a);
  printf("\nbit2: %s\n", is_bit_on(a, 2) ? "on" : "off");

  printf("before swap\n");
  printf("c: %d, d: %d\n", c, d);
  swap(&c, &d);
  printf("after swap\n");
  printf("c: %d, d: %d\n", c, d);

  printf("\n\nturn off right most bit:\n");
  printf("number before:\n");
  print_bits(a);
  turn_off_right_most_bit(&a);
  printf("\nnumber after:\n");
  print_bits(a);

  printf("\nnumber: 128, power of two: %s\n", is_power_of_two(128) ? "true" : "false");
  printf("number: 25, power of two: %s\n", is_power_of_two(25) ? "true" : "false");
}

bool is_bit_on(unsigned int number, int n) {
  // we needa make a mask for that, shifting 1 to get a 1 bit at the 
  // positio we wanna test, we can then test using &.
  return number & (0x1 << n);
}

void print_bits(unsigned int n) {
  for (int i = 31; i >= 0; i--) {
    if (is_bit_on(n, i)) {
      printf("1");
    } else {
      printf("0");
    }

    if (i % 8 == 0) printf(" ");
  }
}

void turn_on_bit(unsigned int *number, int n) {
  *number = *number | (0x1 << n);
}

void turn_off_bit(unsigned int *number, int n) {
  *number = *number & ~(0x1 << n);
}

void swap(int *a, int *b) {
  *a = *a ^ *b;
  *b = *b ^ *a; 
  *a = *a ^ *b;
}

void turn_off_right_most_bit(unsigned int *number) {
  *number = *number & (*number - 1);
}

bool is_power_of_two(unsigned int number) {
  // turn off the rightmost 1 and check if the result is 0.
  return (number & (number - 1)) == 0;
}
