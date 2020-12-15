// Second assignment from the repl.it
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define True 1
#define False 0

int algarismNum(int num, int position);
int sizeNum(int num);
int sumSquares(int num);
int isImpostor(int num);

int main(void)
{
  int number;
  scanf("%d", &number);

  if(isImpostor(number))
    printf("SIM");
  else
    printf("NAO");
  
  return 0;
}

int sizeNum(int num)
{
  int rest, i = 1, size = 0;

  while (rest != num)
  {
    rest = num % (int)pow(10, i);
    size++;
    i++;
  }

  return size;
}

int algarismNum(int num, int position)
{
  int algarism, number2, number3;

  number2 = num % (int)pow(10, position);
  number3 = num % (int)pow(10, position - 1);
  algarism = number2 - number3;
  algarism /= (int)pow(10, position - 1);

  return algarism;
}

int sumSquares(int num)
{
  int i, sum = 0;
  for(i = 1; i <= sizeNum(num); i++)
    sum += pow(algarismNum(num, i), 2); 

  return sum;
}

int isImpostor(int num)
{
  int i = 0;
  int sumSquare = sumSquares(num);

  if (num <= 10)
    return (num == 7 || num == 1 || num == 10) ? True : False;

  while (i < num)
  {
    if (sumSquare == 1)
     return True;

    sumSquare = sumSquares(sumSquare);
    i++;
  }
  return False;
}
