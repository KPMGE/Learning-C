// Using colors in the terminal with C
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

void black() {
  printf("\033[1;30m");
}

void red() {
  printf("\033[1;31m");
}

void green() {
  printf("\033[1;32m");
}

void yellow() {
  printf("\033[1;33m");
}

void blue() {
  printf("\033[1;34m");
}

void purple() {
  printf("\033[1;35m");
}

void cyan() {
  printf("\033[1;36m");
}

void white() {
  printf("\033[1;37m");
}

void reset() {
  printf("\033[0m");
}

int main(void) {

  black();
  printf("this is a black text\n");
  reset();

  red();
  printf("this is a red text\n");
  reset();

  green();
  printf("this is a green text\n");
  reset();

  yellow();
  printf("this is a yellow text\n");
  reset();

  blue();
  printf("this is a blue text\n");
  reset();

  purple();
  printf("this is a purple text\n");
  reset();

  cyan();
  printf("this is a cyan text\n");
  reset();

  white();
  printf("this is a white text\n");
  reset();

  return 0;
}
