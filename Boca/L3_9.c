// Exercise: L3_9 
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define True 1
#define False 0

int verificapH(float pH);
int verificaGotaChuvaAcida(float pH);
float porcentagem(float total, float valor);
void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal);

int main(void)
{
  int A, D, T;
  int qtdAdcido = 0, qtdBasico = 0, qtdNeutro = 0;
  float totalGotas, chuvaAcida = 0, chuvaNormal = 0;
  float pH, maisAcido = 7, maisBasico = 7, maisNeutro;

  scanf("%d %d %d", &A, &D, &T);

  int i, nGotas = (A * D * T);
  for (i = 0; i < nGotas; i++)
  {
    scanf("%f", &pH);

    if (i == 0)
      maisNeutro = pH;
    if (fabs(pH - 7) < fabs(maisNeutro - 7))
      maisNeutro = pH;
    if (verificapH(pH) == 0)
      qtdNeutro++;
    if (verificapH(pH) == 1)
      qtdAdcido++;
    if (verificapH(pH) == 2)
      qtdBasico++;
    if (pH < maisAcido)
      maisAcido = pH;
    if (pH > maisBasico)
      maisBasico = pH;
    if (verificaGotaChuvaAcida(pH))
      chuvaAcida++;
    else
      chuvaNormal++;
  }

  totalGotas = chuvaNormal + chuvaAcida;
  if (nGotas == 0)
    printf("Nenhuma gota foi avaliada");
  else
  {
    printf("%d %d %d %.2f %.2f %.2f\n", qtdAdcido, qtdBasico, qtdNeutro, maisAcido, maisBasico, maisNeutro);
    imprimeResultadosAnalise(porcentagem(totalGotas, chuvaAcida), porcentagem(totalGotas, chuvaNormal));
  }

  return 0;
}

int verificapH(float pH)
{
  if (pH == 7)
    return 0;
  else if (pH < 7)
    return 1;
  else
    return 2;
}

int verificaGotaChuvaAcida(float pH)
{
  return (pH < 5.7) ? True : False;
}

float porcentagem(float total, float valor)
{
  return (valor * 100) / total;
}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal)
{
  if (porcentagemGotasChuvaAcida >= 75.00)
    printf("Chuva Acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
  else if (porcentagemGotasChuvaNormal >= 75.00)
    printf("Chuva Normal %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
  else
    printf("Chuva com indicios de chuva acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
}