#include <stdio.h>

int main(void)
{
  int number;

  //the scanf function returns 0 if some error to occur, otherwise, it returns a value equal than number of readed variables
  while(scanf("%d", &number))
    printf("The number entered is %d\n", number);
  
  //if the user enter a non-number
  printf("you entered an invalid value");

  return 0;
}