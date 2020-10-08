#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int number;
  srand(time(NULL));
  printf("you may bet in the sequence: ");
  for(int i = 0; i < 6; i++)
  {
    number = rand() % 60;
    if(!number)
      number++;
    printf("%d ", number);
  }

  return 0;
  }
