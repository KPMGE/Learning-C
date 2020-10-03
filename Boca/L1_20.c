/*(BOCA:L1_20) 
Problema: Dados o mês e o ano como números inteiros,
informe qual é o mês correspondente, o número de dias, o ano e se é
bissexto. Use o comando switch. Se o valor informado como entrada
para o mês não for um inteiro entre 1 e 12 ou se o ano for um inteiro
negativo, o seu programa deve indicar que a opção é inválida.

Entrada: dois valores inteiros separados por espaço em branco.

Saída: a palavra que identifica o mês, um inteiro que representa o
número de dias do mês, o ano e a palavra bissexto, apenas quando o ano
atende a essa condição.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int month, year;

  scanf("%d %d", &month, &year);

  switch(month)
  {
    case 1:
      printf("janeiro 31 %d ", year);
      if((year % 4) == 0)
        printf("bissexto");
      printf("\n");
      break;

    case 2:
      printf("fevereiro 28 %d ", year);
      if((year % 4) == 0)
        printf("bissexto");
      printf("\n");
      break;

    case 3:
      printf("marco 31 %d ", year);
      if((year % 4) == 0)
        printf("bissexto");
      printf("\n");
      break;

    case 4:
      printf("abril 30 %d ", year);
      if((year % 4) == 0)
        printf("bissexto");
      printf("\n");
      break;

    case 5:
      printf("maio 31 %d ", year);
      if((year % 4) == 0)
        printf("bissexto");
      printf("\n");
      break;

    case 6:
      printf("junho 30 %d ", year);
      if((year % 4) == 0)
        printf("bissexto");
      printf("\n");
      break;

    case 7:
      printf("julho 31 %d ", year);
      if((year % 4) == 0)
        printf("bissexto");
      printf("\n");
      break;

    case 8:
      printf("agosto 30 %d ", year);
      if((year % 4) == 0)
        printf("bissexto");
      printf("\n");
      break;

    case 9:
      printf("setembro 31 %d ", year);
      if((year % 4) == 0)
        printf(" bissexto");
      printf("\n");
      break;

    case 10:
      printf("outubro 30 %d ", year);
      if((year % 4) == 0)
        printf("bissexto");
      printf("\n");
      break;

    case 11:
      printf("novembro 31 %d ", year);
      if((year % 4) == 0)
        printf("bissexto");
      printf("\n");
      break;

    case 12:
      printf("dezembro 30 %d ", year);
      if((year % 4) == 0)
        printf("bissexto");
      printf("\n");
      break;

    default:
      printf("opcao invalida\n");
 }

  return 0;
}
