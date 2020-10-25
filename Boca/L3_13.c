// Exercise: Monitoria 4
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int isPrime(int num);
int sumWord(char letter);
int isLowercase(char letter);
int codeLetter(char letter);
int nextPrime(int num);

int main(void)
{
  char letter;
  int sum;

  while (scanf("%c", &letter) == 1)
  {
    sum = sumWord(letter);
    if (isPrime(sum))
      printf("E primo\n");
    else
      printf("Nao e primo %d\n", nextPrime(sum));
  }

  return 0;
}

int isPrime(int num)
{
  int i;
  if (num < 2)
    return False;
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
  if (isLowercase(letter))
    return letter - 'a' + 1;
  else
    return letter - 38;
}

int sumWord(char letter)
{
  int sum = 0;
  char letter2;
  while ((letter2 = getchar()) != '\n' || letter2 == ' ')
    sum += codeLetter(letter2);

  return sum + codeLetter(letter);
}

int nextPrime(int num)
{
  while (True)
  {
    num++;
    if (isPrime(num))
      return num;
  }
}