#include <stdio.h>
#include <stdlib.h>

int main()
{
  //declaração de variaveis
  int a, cont = 0, maior = 0;
  float media = 0, mediafinal;

  //loop infito
  while (1)
  {
    //leitura dos dados
    scanf("%d", &a);

    //caso o valor digitado seja 0, interrompemos o programa
    if (a == 0)
    {
      break;
    }

    //a media é incrementada ao valor de a, eo contador, incrementado em uma unidade
    media += a;
    cont++;

    //calculando a media final
    mediafinal = media / cont;

    //se o valor digitado seja maior que o maior valor ate então, maior = esse valor
    if (a > maior)
    {
      maior = a;
    }

    //mostrando o resultado final na tela
    printf("%d %f\n", maior, mediafinal);
  }

  return 0;
}
