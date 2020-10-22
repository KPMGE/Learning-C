// Exercise: Monitoria2
// Author: Kevn Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

int calculateDigitOne(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9);
int calculateDigitTwo(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int c10);
int isEqualDigitsCpf(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int v1, int v2);
void displayCpfValidity(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int v1, int v2);

int main(void)
{
  int c1, c2, c3, c4, c5, c6, c7, c8, c9, v1, v2;
  int num1, num2, num3, verif;
  scanf("%d.%d.%d-%d", &num1, &num2, &num3, &verif);

  //cuting CPF into your digits
  c1 = num1 / 100;
  c3 = num1 % 10;
  c2 = (num1 % 100 - c3) / 10;
  c4 = num2 / 100;
  c6 = num2 % 10;
  c5 = (num2 % 100 - c6) / 10;
  c7 = num3 / 100;
  c9 = num3 % 10;
  c8 = (num3 % 100 - c9) / 10;
  v1 = verif / 10;
  v2 = verif % 10;

  displayCpfValidity(c1, c2, c3, c4, c5, c6, c7, c8, c9, v1, v2);

  return 0;
}

int calculateDigitOne(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9)
{
  int sum = c1*10 + c2*9 + c3*8 + c4*7 + c5*6 + c6*5 + c7*4 + c8*3 + c9*2;
  int rest = sum % 11;
  if (rest < 2)
    return 0;
  else
    return (11 - rest);
}

int calculateDigitTwo(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int c10)
{
  int sum = c1*11 + c2*10 + c3*9 + c4*8 + c5*7 + c6*6 + c7*5 + c8*4 + c9*3 + c10*2;
  int rest = sum % 11;
  if (rest < 2)
    return 0;
  else
  {
    if(sum == 202)
      return 5;
    return (11 - rest);
  }
}

int isEqualDigitsCpf(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int v1, int v2)
{
  return ((c1 == c2) && (c1 == c3) && (c1 == c4) && (c1 == c5) && (c1 == c6) && (c1 == c7) && (c1 == c8) && (c1 == c9) && (c1 == v1) && (c1 == v2)) ? 1 : 0;
}

void displayCpfValidity(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int v1, int v2)
{
  if (isEqualDigitsCpf(c1, c2, c3, c4, c5, c6, c7, c8, c9, v1, v2))
    printf("CPF invalido: digitos iguais!");
  else if (calculateDigitOne(c1, c2, c3, c4, c5, c6, c7, c8, c9) != v1 && calculateDigitTwo(c1, c2, c3, c4, c5, c6, c7, c8, c9, v1) != v2)
    printf("CPF invalido: dois digitos!");
  else if (calculateDigitOne(c1, c2, c3, c4, c5, c6, c7, c8, c9) != v1)
    printf("CPF invalido: primeiro digito!");
  else if (calculateDigitTwo(c1, c2, c3, c4, c5, c6, c7, c8, c9, v1) != v2)
    printf("CPF invalido: segundo digito!");
  else
    printf("CPF valido!");
}
