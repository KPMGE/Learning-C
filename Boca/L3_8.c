/*
(BOCA: L3_8)
 Problema: Você subestimou o nível de conhecimento de
Padi desde a última vez que o ajudou e agora ele terminou a Lista 3
antes que você. Para provar que é mais rápido e treinar seus
conhecimentos em implementação de funções, você deve fazer um
programa que, dado o tamanho de uma matrix e seus valores, que
nunca são iguais, transforma seus valores no próximo número primo
maior que o próprio valor se o valor é positivo e menor que o próprio
valor se o valor é negativo. Caso o valor já seja primo ou se o primo
transformado extrapolar os intervalos de entrada possível, o programa
não deve fazer nenhuma mudança.

a) Seu programa deve conter a função int is_prime(int n) que
retorna 1 se o número n passado como parâmetro for primo ou 0 caso
contrário.

b) Seu programa deve conter a função int transform_prime(int n)
que transforma o número n passado como parâmetro no próximo maior
ou menor primo retornando o número transformado.

c) Seu programa deve conter a função int is_negative(int n) que
retorna 1 se o número for negativo ou 0 caso contrário.

Entrada: uma linha com os valores L (1 <= L <= 100) e C (1 <= C <=
100), representando o tamanho da matrix em rows e columns,
respectivamente. Depois, L rows com C valores V (-32000 <= V <=
32000) cada.

Saída: a matrix com seus valores transformados, conforme exemplo
abaixo.
*/

#include <stdio.h>

//creating boolean values
#define TRUE 1
#define FALSE 0

//function that checks if the number is negative
int is_negative(int n);
//function that checks if the number is a prime number
int is_prime(int n);
//function that transforms the number to next prime number
int transform_prime(int n);

int main(void)
{
  int rows, columns;
  scanf("%d %d", &rows, &columns);

  //declaring matrices
  int matrix[rows][columns], matrixResult[rows][columns];

  //reading matrix
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
          return 0;
      }
      return 1;
    }
    else
    {
      for (i = 2; i <= n / 2; i++)
      {
        //if 'n' is divisible by 'i', n isn't a prime number
        if (n % i == 0)
          return 0;
      }
      return 1;
    }
  }
  else
    return 0;
}

int transform_prime(int n)
{
  //variable with smallest positive prime number
  int i = 2;

  //if the number is prime, we return it
  if (is_prime(n))
    return n;

  //to transform to next negative prime number
  if (is_negative(n))
  {
    //smallest negative prime number
    i = -2;

    while (TRUE)
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
    while (TRUE)
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
