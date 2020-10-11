#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcularDistancia(int x, int y);

int main(void)
{
  float distanciaOrigem, maiorValor;
  int x, y, i, xMaior, yMaior;

  //lendo o primeiro ponto
  scanf("%d %d", &x, &y);
  maiorValor = calcularDistancia(x, y);
  xMaior = x;
  yMaior = y;
  printf("%.2f ", maiorValor);

  //lendo os demais pontos
  for(i = 1; i <= 4; i++)
  {
    scanf("%d %d", &x, &y);
    distanciaOrigem = calcularDistancia(x, y);

    if(maiorValor <= distanciaOrigem)
    {
      maiorValor = distanciaOrigem;
      xMaior = x;
      yMaior = y;
    }

    printf("%.2f ", distanciaOrigem);
  }

  printf("Maior: %.2f p: (%d,%d)", maiorValor, xMaior, yMaior);

  return 0;
}

float calcularDistancia(int x, int y)
{
  float distancia;
  distancia = sqrt(pow(x, 2) + pow(y, 2));
  return distancia;
}
