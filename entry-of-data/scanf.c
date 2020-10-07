#include <stdio.h>

int main(void)
{
  char letter1, letter2;
  int number;

  //reading 3 variables and cheking if the value returned by scanf is 3
  if(scanf("%d %c %c", &number, &letter1, &letter2) == 3)
    printf("there are no errors");
  else
    printf("happened an error. You digited an incompatible value");
  
  return 0;
}