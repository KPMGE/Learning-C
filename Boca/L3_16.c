#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int isLetter(char character);

int main(void)
{
  char character;
  int qtdLetters = 0;

  while(True)
  {
    scanf("%c", &character);
    if(character == '.')
      break;
    if(isLetter(character))
      qtdLetters++;
  }
    
  printf("RESP: %d", qtdLetters);

  return 0;
}

int isLetter(char character)
{
  return ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) ? True : False;
}