// Exercise: L4_11
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
  int code;
  float value;
} Billet;

void displayBillet(Billet billet);

int main(void)
{
  int qtdBillets, i;
  float sumBillets = 0;
  Billet billet, expensiverBillet, cheaperBillet;

  scanf("%d", &qtdBillets);

  for (i = 0; i < qtdBillets; i++)
  {
    scanf("%d %f", &billet.code, &billet.value);

    sumBillets += billet.value;

    if (i == 0)
      expensiverBillet = cheaperBillet = billet;
    else if (billet.value < cheaperBillet.value)
      cheaperBillet = billet;
    else if (billet.value > expensiverBillet.value)
      expensiverBillet = billet;
  }

  printf("Mais caro: ");
  displayBillet(expensiverBillet);
  printf("Mais barato: ");
  displayBillet(cheaperBillet);
  printf("Soma: %.2f", sumBillets);

  return 0;
}

void displayBillet(Billet billet)
{
  printf("Cod: %d valor: %.2f\n", billet.code, billet.value);
}