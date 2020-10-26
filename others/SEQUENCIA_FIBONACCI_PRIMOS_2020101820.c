// exercise 4
// author: Kevin Carvalho de jesus

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int isPrime(int n);
void displayFibonacciPrimes(int n);

int main(void)
{
  int n;
  scanf("%d", &n);

  //ensuring that will be displayed some value
  if(n < 1)
    n = 1;

  displayFibonacciPrimes(n);

  return 0;
}

int isPrime(int n)
{
  int i;
  for (i = 2; i < n; i++)
    if(n % i == 0)
      return False;
  return True;
}

void displayFibonacciPrimes(int n)
{
  int cont = 1, sum = 0, previous = 1, next = 1;

  while (cont <= n)
  {
    sum = previous + next;
    previous = next;
    next = sum;
    if (isPrime(sum))
    {
      printf("%d ", sum);
      cont++;
    }
    sum = 0;
  }
}
