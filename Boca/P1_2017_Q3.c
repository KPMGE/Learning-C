// Exercise: P1_2017_Q3
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define True 1
#define False 0

int isEqual(char c1, char c2, char c3, char c4);
int isLetter(char c);
int isValidCode(char c1, char c2, char c3, char c4);

int main(void)
{
  char c1, c2, c3, c4;

  scanf("%c%c %c%c", &c1, &c2, &c3, &c4);

  if(isValidCode(c1, c2, c3, c4))
  {
    if(isEqual(c1, c2, c3, c4))
      printf("IGUAIS");
    else
      printf("DIFERENTES");
  }
  else
    printf("Invalido");

  return 0;
}

int isLetter(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? True : False;
}

int isValidCode(char c1, char c2, char c3, char c4)
{
  return ((isdigit(c1) || isLetter(c1)) && (isdigit(c2) || isLetter(c2)) && (isdigit(c3) || isLetter(c3)) && (isdigit(c4) || isLetter(c4))) ? True : False;
}

int isEqual(char c1, char c2, char c3, char c4)
{
  if(isLetter(c1) && isLetter(c2) && isLetter(c3) && isLetter(c4))
  {
    if((toupper(c1) == toupper(c3)) && (toupper(c2) == toupper(c4)))
      return True;
  }
  else if(isLetter(c1) && isLetter(c3))
    return ((toupper(c1) == toupper(c3)) && (c2 == c4)) ? True : False;
  else 
    return ((toupper(c2) == toupper(c4)) && (c1 == c3)) ? True : False;
}