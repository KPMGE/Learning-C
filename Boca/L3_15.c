#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcularDistancia(int x, int y);

int main(void)
{
  float distanciaOrigem, maiorValor;
  int x, y, i, xMaior, yMaior, alreadyAssigned = 1;

  //lendo os demais pontos
  for(i = 1; i <= 5; i++)
  {
    scanf("%d %d", &x, &y);

    if(alreadyAssigned)
    {
      maiorValor = calcularDistancia(x, y);
      alreadyAssigned = 0;
      xMaior = x;
      yMaior = y;
    }

    distanciaOrigem = calcularDistancia(x, y);
    if(maiorValor < distanciaOrigem)
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
  return sqrt(pow(x, 2) + pow(y, 2));
}

