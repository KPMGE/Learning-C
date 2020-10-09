/*(BOCA:L3_11) Problema: Implemente um programa que dado a relação de números par ou
impar, retorne os N primeiros números desse tipo. Para isso, crie funções que dizem se o
número é par ou ímpar, uma função para printar os N primeiros pares a partir do 2 e uma
função para printar os N primeiros números ímpares a partir do 1.
As funções deverão ter os seguintes cabeçalhos:
a) int EhPar (int x)
b) void PrintaPares (int N)
c) void PrintaImpares (int N)
Obs: Cada numero na saída é separado por um único espaço.

Entrada: A entrada é dada por TIPO, sendo 0 para PAR e 1 para IMPAR, e N, onde N está
entre 1<=N<=99999.
Saída: Os N primeiros números do tipo pedido (par/ímpar).*/

#include <stdio.h>

int EhPar(int x);
void PrintaPares(int n);
void PrintaImpares(int n);

int main(void)
{
  int n, tipo;

  scanf("%d", &tipo);

  switch (tipo)
  {
    case 0:
      scanf("%d", &n);
      PrintaPares(n);
    break;

    case 1:
      scanf("%d", &n);
      PrintaImpares(n);
    break;
  }

  return 0;
}

int EhPar(int num)
{
  //caso o resto da divisão do numero por 2 for 0, o numero é par
  return (num % 2 == 0) ? 1 : 0;
}

void PrintaPares(int n)
{
  int i, num = 2;
  for(i = 0; i < n; i++, num++)
  {
    if (EhPar(num))
      printf("%d ", num);
    else
    {
      num++;
      printf("%d ", num);
    }
  }
}

void PrintaImpares(int n)
{
  int i, num = 1;
  for(i = 0; i < n; i++, num++)
  {
    if (!EhPar(num))
      printf("%d ", num);
    else
    {
      num++;
      printf("%d ", num);
    }
  }
}