#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int isLetter(char c);
int isDigit(char c);
int checkLettersPlate(char c1, char c2, char c3);
int checkNumbersPlate(char c1, char c2, char c3);
void displayPlateValidity(char c1, char c2, char c3, char c4, char c5, char c6); 

int main(void)
{
  char c1, c2, c3, c4, c5, c6;

  scanf("%c%c%c-%c%c%c", &c1, &c2, &c3, &c4, &c5, &c6);
  displayPlateValidity(c1, c2, c3, c4, c5, c6);

  return 0;
}

int isLetter(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? True : False;
}

int isDigit(char c)
{
  return (c >= '0' && c <= '9') ? True : False;
}

int checkLettersPlate(char c1, char c2, char c3)
{
  return (isLetter(c1) && isLetter(c2) && isLetter(c3)) ? True : False;
}

int checkNumbersPlate(char c1, char c2, char c3)
{
  return (isDigit(c1) && isDigit(c2) && isDigit(c3)) ? True : False;
}

void displayPlateValidity(char c1, char c2, char c3, char c4, char c5, char c6)
{
  if (checkLettersPlate(c1, c2, c3) && checkNumbersPlate(c4, c5, c6))
    printf("Codigo valido!");
  else if (!checkLettersPlate(c1, c2, c3) && !checkNumbersPlate(c4, c5, c6))
    printf("Codigo invalido!Problema nas letras e nos numeros!");
  else if (checkLettersPlate(c1, c2, c3))
    printf("Codigo invalido!Problema nos numeros!");
  else
    printf("Codigo invalido!Problema nas letras!");
} 
