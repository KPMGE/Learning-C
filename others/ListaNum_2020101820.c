#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int firstNumber, number, qtdOdd=0, qtdEven=0, qtdNumbers;
  scanf("%d", &qtdNumbers);

  int i;
  for (i = 0; i < qtdNumbers; i++)
  {
    scanf("%d", &number);
    if(i == 0)
      firstNumber = number;
    if(number % 2 == 0)
      qtdEven++;
    else
      qtdOdd++;
  }

  if(firstNumber % 2 == 0)
    printf("QTD PARES:%d", qtdEven);
  else
    printf("QTD IMPARES:%d", qtdOdd);

  return 0;
}
