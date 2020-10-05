/*(BOCA:L2_9) Problema: Faça um programa que imprima os números primos contidos em um intervalo n e m fornecidos pelo usuário seguidos por seus múltiplos até o final do intervalo.

Entrada: Seu programa deverá receber dois inteiros n e m, indicando o intervalo a ser avaliado. Considere que n e m formem um intervalo aberto, ou seja, n e m não precisam ser avaliados. Considere também que n sempre seja menor que m.

Saída: Como saída, o programa deverá exibir todos os números primos contidos no intervalo aberto (n,m) e também seus múltiplos. Cada número primo do intervalo deverá ser impresso em uma linha separada, e seus múltiplos deverão ser todos impressos na linha seguinte .Caso não haja primo no intervalo, não imprima nada*/

#include <stdio.h>

int main()
{
  //variaveis principais
  int n, m, primo = 0;

  //lendo os valores de n e m
  scanf("%d%d", &n, &m);

  //incremento a n, pois o intervalo é aberto
  n++;

  //for de n ate m
  for (n; n < m; n++)
  {
    //menor primo definido
    int minPrimo = 2;
    //while enquanto o minprimo menor que n
    while (minPrimo < n)
    {
      //se o numero é divisivel, primo incrementado
      if (n % minPrimo == 0)
      {
        primo++;
      }

      //incremento a minprimo
      minPrimo++;
    }

    //caso a variavel primo se mantenha como 0, n é primo
    if (primo == 0)
    {
      //definindo variaveis
      int i = 2, multiplo, teste = 0;

      //mostrando o numero n , correspondente ao loop
      printf("%d\n", n);

      //loop indefinido
      while (1)
      {
        //multiplo recebe o valor de n, vezes o valor de i
        multiplo = n * i;

        //caso o multiplo seja maior ou igual que m, que é o numero fina, paramos o loop
        if (multiplo >= m)
        {
          break;
        }
        //caso contrario, mostramos o multiplo e incrementamos teste
        else
        {
          printf("%d ", multiplo);
          teste++;
        }

        //incremento a variavel i
        i++;
      }

      //caso o teste se mantenha como 0, sabemos que somente um loop foi executadoo, logo o numero em questao nao tem multiplos
      if (teste == 0)
      {
        printf("*\n");
      }
      //caso contrario apenas damos um espaço para a proxima exibiçao
      else
      {
        printf("\n");
      }

      //resetando a variavel teste, para realizar uma nova comparação
      teste = 0;
    }

    //resetando a variavel minPrimo e primo, para realizar uma nova comparação
    minPrimo = 2;
    primo = 0;
  }

  return 0;
}
