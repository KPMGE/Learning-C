// Exercise: L3_8
// Author: Kevin Carvalho de jesus

#include <stdio.h>

//creating boolean values
#define True 1
#define False 0

int is_negative(int n);
int is_prime(int n);
int transform_prime(int n);

int main(void)
{
  int rows, columns;
  scanf("%d %d", &rows, &columns);

  int matrix[rows][columns], matrixResult[rows][columns];

  int i, j;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < columns; j++)
      scanf("%d", &matrix[i][j]);
  }

  //creating matrix to result
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < columns; j++)
      matrixResult[i][j] = transform_prime(matrix[i][j]);
  }

  //displaying matrix result
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < columns; j++)
    {
      printf("%d ", matrixResult[i][j]);
    }
    printf("\n");
  }

  return 0;
}

int is_negative(int n)
{
  return (n < 0) ? 1 : 0;
}

int is_prime(int n)
{
  int i;

  //if the number is different than 1, -1 and 0
  if (n != 1 && n != -1 && n != 0)
  {
    //if the number is positive
    if (n < 0)
    {
      for (i = -2; i >= n / 2; i--)
      {
        //if 'n' is divisible by 'i', n isn't a prime number
        if (n % i == 0)
          return False;
      }
      return True;
    }
    else
    {
      for (i = 2; i <= n / 2; i++)
      {
        //if 'n' is divisible by 'i', n isn't a prime number
        if (n % i == 0)
          return False;
      }
      return True;
    }
  }
  else
    return False;
}

int transform_prime(int n)
{
  int i = 2;

  //if the number is prime, we return it
  if (is_prime(n))
    return n;

  //to transform to next negative prime number
  if (is_negative(n))
  {
    //smallest negative prime number
    i = -2;

    while (True)
    {
      //if i is small than n
      if (i < n)
      {
        //if 'i' is a prime number, we return it
        if (is_prime(i))
          return i;
      }

      i--;

      //if 'i' is small than -32000, we return it
      if (i < -32000)
        return n;
    }
  }

  // to transform to next positive prime number
  else
  {
    while (True)
    {
      //if 'i' is greater than n
      if (i > n)
      {
        //if 'i' is a prime number, we return it
        if (is_prime(i))
          return i;
      }

      i++;

      //if 'i' is greater than 32000, we return it
      if (i > 32000)
        return n;
    }
  }
}
