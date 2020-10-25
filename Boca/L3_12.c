// Exercise L3_12 ~ BOCA  
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define True 1
#define False 0

void parImpar(int n);
void valorPrimo(int n);
int verificaPrimo(int n);
int tamanhoNum(int n);
int algarismoNum(int n, int posicao);
int algarismoNum(int n, int posicao);
int somadosdigitos(int n);

int main(void)
{
  int valor, soma = 0;

  scanf("%d", &valor);

  do
  {
    soma = somadosdigitos(valor);
    printf("%d ", soma);
    parImpar(soma);
    valorPrimo(soma);
    valor = soma;
  } while (soma > 9);

  return 0;
}

void parImpar(int n)
{
  if (n % 2 == 0)
    printf("Par ");
  else
    printf("Impar ");
}

int verificaPrimo(int n)
{
  int i;

  if(n < 2)
    return False;

  for (i = 2; i < n / 2; i++)
  {
    if (n % i == 0)
      return False;
  }
  return True;
}

void valorPrimo(int n)
{
  if (verificaPrimo(n))
    printf("Primo\n");
  else
    printf("Nao e primo\n");
}

int tamanhoNum(int n)
{
  int tamanho = 0, resto = 0, i = 1;

  while (resto != n)
  {
    resto = n % (int)pow(10, i);
    tamanho++;
    i++;
  }
  return tamanho;
}

int algarismoNum(int n, int posicao)
{
  int algarismo, n2, n3;

  n2 = n % (int)pow(10, posicao);
  n3 = n % (int)pow(10, posicao - 1);
  algarismo = n2 - n3;
  algarismo /= (int)pow(10, posicao - 1);

  return algarismo;
}

int somadosdigitos(int n)
{
  int i, tamanho, algarismo = 0, soma = 0;
  tamanho = tamanhoNum(n);

  for (i = 1; i <= tamanho; i++)
  {
    algarismo = algarismoNum(n, i);
    soma += algarismo;
    algarismo = 0;
  }
  return soma;
}
