
/*
(BOCA:L2_15) 
Problema: Faça um programa para imprimir a quantidade de números negativos, a quantidade de números positivos, a soma dos negativos e a soma dos positivos de uma sequência de números. O programa deverá ler números da entrada padrão (um por vez) enquanto ainda tiverem números para serem lidos. Considere que os números estão entre -100 e 100.
Entrada: uma sequência números inteiros separados por esumPositiveaço e terminada por um caractere diferente de white-space (ver ajuda do scanf).
Saída: a quantidade de números negativos da sequência, a quantidade de números positivos da sequência, a soma dos números negativos da sequência e a soma dos números positivos da sequência.
*/

#include <stdio.h>

//function that ckecks if 'c' is a white-space
int differentWhiteSpace(char c);

int main(void)
{
  int i, sumPositive = 0, sumNegative = 0, qtdNegative = 0, qtdPositive = 0, number;

  for (i = 0; i < 100; i++)
  {
    scanf("%d", &number);

    if (differentWhiteSpace(number))
      break;

    //if the number entered is greater than 0
    else if (number > 0)
    {
      sumPositive += number;
      qtdPositive++;
      number = 0;
    }
    //if the number entered is less than 0
    else if (number < 0)
    {
      sumNegative += number;
      qtdNegative++;
      number = 0;
    }
  }

  //displaying results
  printf("%d %d %d %d", qtdNegative, qtdPositive, sumNegative, sumPositive);

  return 0;
}

int differentWhiteSpace(char c)
{
  if ((c < -100) || (c > 100))
  {
    if ((c != '\n') || (c != '\t') || (c != ' ') || (c != '\v') || (c != '\f') || (c != '\r'))
      return 1;
  }
  else
    return 0;
}
