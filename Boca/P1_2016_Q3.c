#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define True 1
#define False 0

int isLetter(char c);
int isCapitalLetter(char c);
int isLowercaseConsoant(char c);
int isVowel(char c);
int isValid(char c1, char c2, char c3, char c4);


int main(void)
{
  char character1, character2, character3, character4;

  scanf("%c%c%c%c", &character1, &character2, &character3, &character4); 

  if(isValid(character1, character2, character3, character4))
    printf("%c%c%c%c", character1, character2, toupper(character3), toupper(character4));
  else
    printf("Invalido");
  
  return 0;
}

int isLetter(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? True : False;
}

int isCapitalLetter(char c)
{
  return (c >= 'A' && c <= 'Z') ? True : False;
}

int isVowel(char c)
{
  return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U')) ? True : False;
}

int isLowercaseConsoant(char c)
{
  return (isLetter(c) && !isCapitalLetter(c) && !isVowel(c)) ? True : False;
}

int isValid(char c1, char c2, char c3, char c4)
{
  return (isCapitalLetter(c1) && isdigit(c2) && isVowel(c3) && isLowercaseConsoant(c4)) ? True : False;
}