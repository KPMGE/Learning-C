/*(BOCA:L2_16) 
Problema: Dado duas sequências de números, faça um
programa que imprima o menor número da primeira sequência seguido da
posições primeira e última que ele aparece na segunda sequência. Caso o
menor número da primeira sequência não apareça na segunda nenhuma
vez, o programa deverá considerar o tamanho da segunda sequência
como primeira e última posições.

Entrada: duas linhas com os números das duas sequências, com um
caractere não numérico no final de cada linha. Cada número está contido
em um intervalo [-32000, 32000].

Saída: menor número da primeira sequência, posições da primeira e última
vez que o menor da primeira aparece na segunda sequência. Caso o
menor da primeira não apareça nenhuma vez, utilizar o tamanho da
segunda sequência como primeira e última ocorrência. Considerar a
posição começando em 0.*/

#include <stdio.h>
#include <stdlib.h>

/* 
 * 
 */
int main()
{
  int menor, numero, i, p, posicao, primeiro, ultimo;

  i = 0;
  p = 0;
  posicao = 0;

  while (scanf("%d ", &numero))
  {
    if (i == 0)
    {
      menor = numero;
      i++;
    }
    if (numero < menor)
      menor = numero;
  }

  scanf("%*c");
  i = 0;

  while (scanf("%d ", &numero))
  {
    if (numero == menor && i == 0)
    {
      primeiro = posicao;
      i++;
    }
    if (numero == menor)
    {
      ultimo = posicao;
      p++;
    }
    if (i == 0)
    {
      primeiro = posicao + 1;
      ultimo = posicao + 1;
    }
    if (i == 1 && p == 0)
    {
      ultimo = primeiro;
    }
    posicao++;
  }

  printf("%d %d %d", menor, primeiro, ultimo);

  return 0;
}
