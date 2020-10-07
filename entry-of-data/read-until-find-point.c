#include <stdio.h>

int main(void)
{
  char letter;

  //reading while letter is different than '.'
  while(letter = getchar() != '.')
  {
    //displaying letter entered
    putchar(letter);
  }

  return 0;
}