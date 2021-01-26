// author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void displayWhiteSpace(int n);
void displayTopDiamond(int n);
void displayBottomDiamond(int n);
void displayDiamond(int num);
char generateRandomCharacter(int seed);

int main(void)
{
  int num;
  scanf("%d", &num);
  displayDiamond(num);
  return 0;
}

char generateRandomCharacter(int seed)
{
  srand(seed);
  char character;

  while(1) 
  {
    character = (rand() / (float)RAND_MAX) * 125;

    if (isgraph(character))
    {
      return character;
    }
  }
}

void displayWhiteSpace(int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf(" ");
}

void displayTopDiamond(int n)
{
  srand(time(NULL));

  int i, j, k = n;
  for (i = 1; i <= n; i++)
  {
    displayWhiteSpace(k);
    for (j = 1; j <= i; j++)
    {
      printf("%c ", generateRandomCharacter(i + (rand() / (float)RAND_MAX) * 100));
    }
    printf("\n");
    k--;
  }
}

void displayBottomDiamond(int n)
{
  srand(time(NULL));

  int i, j, k = 2;
  for (i = n-1; i >= 1; i--)
  {
    displayWhiteSpace(k);
    for (j = 1; j <= i; j++)
    {
      printf("%c ", generateRandomCharacter(i + (rand() / (float)RAND_MAX) * 100));
    }
    printf("\n");
    k++;
  }
}

void displayDiamond(int number) 
{
  displayTopDiamond(number);
  displayBottomDiamond(number);
}