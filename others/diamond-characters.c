// author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

void displayWhiteSpace(int n);
void displayTopDiamond(int n);
void displayBottomDiamond(int n);
void displayDiamond(int num);

int main(void)
{
  int num;
  scanf("%d", &num);
  displayDiamond(num);
  return 0;
}

void displayWhiteSpace(int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf(" ");
}

void displayTopDiamond(int n)
{
  int i, j, k = n;
  for (i = 1; i <= n; i++)
  {
    displayWhiteSpace(k);
    for (j = 1; j <= i; j++)
    {
      printf("%c ", j+32);
    }
    printf("\n");
    k--;
  }
}

void displayBottomDiamond(int n)
{
  int i, j, k = 2;
  for (i = n-1; i >= 1; i--)
  {
    displayWhiteSpace(k);
    for (j = 1; j <= i; j++)
    {
      printf("%c ", j+32);
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
