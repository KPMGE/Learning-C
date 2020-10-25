#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float peso, altura, imc;
  scanf("%f %f", &peso, &altura);
  imc = peso / (altura * altura);
  printf("%.2f", imc);

  return 0;
}
