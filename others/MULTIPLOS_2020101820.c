// exercise3
//author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int isMultiple(int n1, int n2);
int sumNonMultiples(int k, int multi, int m);
void displayNonMultiples(int k, int multi, int m);
void displayMultiples(int n, int m, int k);

int main(void)
{

  int n, m, k;
  do
  {
    scanf("%d %d %d", &n, &m, &k);
  } while (!(k <= n) || !(n <= m));
  displayMultiples(n, m, k);

  return 0;
}

int isMultiple(int n1, int n2)
{
  if (n1 % n2 == 0)
    return True;
  else
    return False;
}
int sumNonMultiples(int k, int multi, int m)
{
  int i, sum = 0;
  for (i = multi+1; i < m; i++)
    if (!isMultiple(i, k))
      sum += i;
  return sum;
}

void displayNonMultiples(int k, int multi, int m)
{
  int i;
  for (i = multi+1; i < m; i++)
    if (!isMultiple(i, k))
      printf("%d ", i);
}

void displayMultiples(int n, int m, int k)
{
  int i = n + 1;
  for (i; i < m; i++)
  {
    if (isMultiple(i, k))
    {
      printf("%d --> ", i);
      displayNonMultiples(k, i, m);
      if(sumNonMultiples(k,i,m) == 0)
        printf(" ");
      else
        printf(": %d\n", sumNonMultiples(k, i, m));
    }
  }
}