#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int x = 10, y; // Assigning to x value 10 
  int *p1;       // A pointer statement

  p1 = &x; // p1 have the x memory address 
  y = *p1; // y have the value in the p1 memory address esta na variavel p1

  printf("The x memory address is: %p\nThe value in that address is: %d\n", p1, y);
  return 0;
}
