// Exercise: L3_19
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

float tempoChegada(float distancia, float velocidade);

int main(void)
{
  int i, qtdCidades;
  float distancia, menorDistancia, velocidade;
  char cidade, cidadeM;

  scanf("%d", &qtdCidades);

  for (i = 0; i < qtdCidades; i++)
  {
    scanf(" %c %f", &cidade, &distancia);
    if(i == 0)
    {
      menorDistancia = distancia;
      cidadeM = cidade;
    }
    else if(distancia < menorDistancia)
    {
      menorDistancia = distancia;
      cidadeM = cidade;
    }
  }
  scanf("%f", &velocidade);

  printf("c: %c d: %.2f t: %.2f", cidadeM, menorDistancia, tempoChegada(menorDistancia, velocidade));

  return 0;
}

float tempoChegada(float distancia, float velocidade)
{
  float tempo = distancia / velocidade;
  return tempo;
}