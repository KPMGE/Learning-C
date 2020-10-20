// Exercise: P1_2017_Q2 - BOCA
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

void displayPeople(int codePerson1, int codePerson2);
int isWoman(int codePerson);

int main(void)
{
  int codePerson1, codePerson2;

  scanf("%d %d", &codePerson1, &codePerson2);

  if ((codePerson1 < 1 || codePerson1 > 10) || (codePerson2 < 1 || codePerson2 > 10))
    printf("Invalido");
  else
    displayPeople(codePerson1, codePerson2);

  return 0;
}

int isWoman(int codePerson)
{
  return (codePerson >= 6 && codePerson <= 10) ? True : False;
}

void displayPeople(int codePerson1, int codePerson2)
{
  if(codePerson1 == codePerson2)
  {
    if(isWoman(codePerson1))
      printf("Uma mulher");
    else
      printf("Um homem");
  }

  else if(isWoman(codePerson1) && isWoman(codePerson2))
    printf("Par de mulheres");

  else if(!isWoman(codePerson1) && !isWoman(codePerson2))
    printf("Par de homens");
  
  else
    printf("Um casal");
}
