// Exercise L3_18 - Boca
// Author: Kevin Carvalho de jesus

#include <stdio.h>
#include <stdlib.h>

float sacar(float valor, float saldo);
float depositar(float valor, float saldo);

int main(void)
{
  int i, qtdOperacoes;
  float saldo, valor;
  char operacao;

  scanf("%f %d", &saldo, &qtdOperacoes);

  for(i = 0; i < qtdOperacoes; i++)
  {
    scanf(" %c %f", &operacao, &valor);

    if(operacao == 'S')
      saldo = sacar(valor, saldo);
    else if(operacao == 'D')
      saldo = depositar(valor, saldo);
  }

  if(saldo == 0)
    printf("Zerado: %.2f", saldo);
  if (saldo > 0)
    printf("Positivo: %.2f", saldo);
  if(saldo < 0)
    printf("Negativo: %.2f", saldo);

  return 0;
}

float sacar(float valor, float saldo)
{
  return saldo - valor;
}

float depositar(float valor, float saldo)
{
  return saldo + valor;
}