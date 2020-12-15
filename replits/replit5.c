// exercicio: 5º replit
// autor: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i = 0, j, alvo;
  int vetor[100];
  char caractere = 'a'; 

  // lendo os dados
  scanf("%*c");
  while (caractere != ']')
  {
    scanf("%d %c", &vetor[i], &caractere);
    i++;
  }
  scanf(",%d", &alvo);

  // analisando a propriedade
  printf("[");
  int k;
  for (j = 0; j < i-1; j++)
  {
    for (k = 1; k < i; k++)
    {
      if ((vetor[j] + vetor[k]) == alvo)
      {
        printf("%d, %d", j, k);
        break;
      }
    }
  }
  printf("]");

  return 0;
}
