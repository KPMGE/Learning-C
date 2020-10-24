// Exercise:  P1_2017_Q1
// Author: Kevin Carvlho De Jesus

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int num1, num2, resultado;
  char operacao;

  scanf("%d %d %c", &num1, &num2, &operacao);

  switch (operacao)
  {
    case '+':
      resultado = num1 + num2;
      printf("RESP:%d", resultado);
      break;

    case '-':
      resultado = num1 - num2;
      printf("RESP:%d", resultado);
      break;

    case '/':
      resultado = num1 / num2;
      printf("RESP:%d", resultado);
      break;

    case '*':
      resultado = num1 * num2;
      printf("RESP:%d", resultado);
      break;

    default:
      printf("Invalido");
      break;
    }

  return 0;
}