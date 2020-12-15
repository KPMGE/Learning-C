// Exercise: seventh replit 
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int size;
void readLineFromMatrix(int matrixLine[], int size);
int checkPrincipalDiagonal(int matrixDiagonal[][size]);
int checkTopDiagonal(int matrixDiagonal[][size], int n);
int checkBottomDiagonal(int matrixDiagonal[][size], int n);
int isConstantDiagonalMatrix(int matrix[][size]);

int main(void)
{
  scanf("%d, ", &size);
  int matrix[size][size];

  scanf("%*c%*c");
  int i;
  for (i = 0; i < size; i++)
  {
    readLineFromMatrix(matrix[i], size);
    scanf("%*c%*c%*c");
  }

  if (isConstantDiagonalMatrix(matrix))
    printf("SIM");
  else
    printf("NAO");

  return 0;
}

void readLineFromMatrix(int matrixLine[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    scanf("%d,", &matrixLine[i]);
}

int isConstantDiagonalMatrix(int matrix[][size])
{
  int i;

  for (i = 0; i < size - 1; i++)
  {
    if (matrix[i][i] != matrix[i + 1][i + 1])
      return 0;
  }

  return 1;
}