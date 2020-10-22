// Exercise: Monitoria 4
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int isPrime(int num);
int sumWord();
int isLowercase(char letter);
int codeLetter(char letter);
int nextPrime(int num);

int main(void)
{
  int sum = sumWord();
  if(isPrime(sum))
    printf("E primo");
  else
    printf("Nao e primo %d", nextPrime(sum));

  return 0;
}

int isPrime(int num)
{
  int i;
  for (i = 2; i < num / 2; i++)
    if (num % i == 0)
      return False;
  return True;
}

int isLowercase(char letter)
{
  return (letter >= 'a' && letter <= 'z') ? True : False;
}

int codeLetter(char letter)
{
  if(isLowercase(letter))
    return letter - 'a' + 1;
  else
    return letter - 38;
}

int sumWord()
{
  int sum = 0;
  char letter;
  while((letter = getchar()) != '\n')
    sum += codeLetter(letter);
  return sum;
}

int nextPrime(int num)
{
  while(True)
  {
    num++;
    if (isPrime(num))
      return num;
  }
}