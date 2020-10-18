// exercise: L3_6 - BOCA  
// author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

#define False 0
#define True 1

int EhPalindromo(int num);

int main(void)
{
  int num;

  while (scanf("%d", &num) == 1)
  {
    if (EhPalindromo(num))
      printf("S\n");
    else
      printf("N\n");
  }

  return 0;
}

int EhPalindromo(int num)
{
  int numOriginal, palindromo, resto;

  numOriginal = num;
  palindromo = 0;

  while (num != 0)
  {
    resto = num % 10;
    palindromo = palindromo + resto;
    num = num / 10;

    if (num != 0)
      palindromo = palindromo * 10;
  }

  if (palindromo == numOriginal)
    return True; 
  else
    return False;
}