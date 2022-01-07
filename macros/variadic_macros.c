// in a variadic macro, everything that is placed in ... is replaced by using
// __VA_ARGS__

#include <stdio.h>

#define for_loop(max, ...)                                                     \
  for (int i = 0; i < max; i++)                                                \
  __VA_ARGS__

int main(int argc, char *argv[]) {

  for_loop(10, printf("hello\n"));

  return 0;
}
