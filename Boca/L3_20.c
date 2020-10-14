/*(BOCA:L3_20) Problema: O prefeito da sua cidade deseja calcular qual seria o consumo de água
em seu bairro, dados o número de casas no bairro, as dimensões das caixas d’água (supondo
que todas as casas usem as mesmas caixas, as dimensões são o raio da base da caixa e a altura),
o número de caixas d’água gastas por dia em cada casa e o número de dias considerado. Seu
programa deve conter as funções float areaCirculo(float raio) e float volumeCaixa(float raio,
float altura), que retornam a área da base da caixa e o volume (capacidade em litros) da caixa.
Utilize o valor de π = 3.141592.

Entrada: número de casas no bairro (inteiro positivo), dimensões das caixas d'águas (raio da
base e altura, ambos números reais positivos), número de casas no bairro (inteiro positivo),
número (real positivo) de caixas d’água gastas por dia e número (inteiro positivo) de dias
considerados.
 Saída: Consumo de água total no formato “Resp: x L”. Precisão de duas casas decimais.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592

float areaCirculo(float raio);
float volumeCaixa(float raio, float altura);
float consumoTotal(int qtdCasa, float raio, float altura, int caixasPorDia, int qtdDias);

int main(void)
{
  int qtdCasas, caixasPorDia, qtdDias;
  float raio, altura, totalConsumo;

  scanf("%d %f %f %d %d", &qtdCasas, &raio, &altura, &caixasPorDia, &qtdDias);

  totalConsumo = consumoTotal(qtdCasas, raio, altura, caixasPorDia, qtdDias);

  printf("Resp: %.2fL", totalConsumo);

  return 0;
}

float areaCirculo(float raio)
{
  return PI * pow(raio, 2);
}

float volumeCaixa(float raio, float altura)
{
  float volume = areaCirculo(raio) * altura;
  return volume;
}

float consumoTotal(int qtdCasa, float raio, float altura, int caixasPorDia, int qtdDias)
{
  float consumoTotal, consumoDiario, volumeCaixas;

  volumeCaixas = volumeCaixa(raio, altura);
  consumoDiario = volumeCaixas * caixasPorDia;
  consumoTotal = consumoDiario * qtdDias;
  return consumoTotal;
}