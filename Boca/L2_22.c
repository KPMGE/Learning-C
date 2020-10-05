/*(BOCA:L2_22) Problema: Dado um inteiro não-negativo, repetidamente some seus
dígitos, até que o resultado tenha somente um dígito.
Por exemplo: 29 = 2 + 9 = 11; 11 = 1 + 1 = 2.
•
• Entrada: um inteiro não negativo.
Saída: “RESP:” seguido de um inteiro correspondente à sum final.*/

#include <stdio.h>
#include <math.h>

//function that returns thre size of the number
int sizeNum(int num);
//function that returns the algarism in the entered position
int algarismNum(int num, int position);

int main(void)
{
  int num, size, algarism, i, sumNum = 0;

  scanf("%d", &num);

  do
  {
    //finding the size of the number
    size = sizeNum(num);
    //reset num variable
    sumNum = 0;

    for (i = 1; i <= size; i++)
    {
      //getting algarism in the position 'i'
      algarism = algarismNum(num, i);
      //increment variable sumNum
      sumNum += algarism;
    }

    //now, num is the sum of the algarisms from previous number
    num = sumNum;
  } while (sumNum > 9);

  printf("RESP:%d", sumNum);

  return 0;
}

int sizeNum(int num)
{
  int rest, i = 1, size = 0;

  while (rest != num)
  {
    rest = num % (int)pow(10, i);

    //incrementing size and i
    size++;
    i++;
  }

  return size;
}

int algarismNum(int num, int position)
{
  int algarism, num2, num3;

  //num2 is the integral number until entered position
  num2 = num % (int)pow(10, position);
  //num3 is num2 less one decimal place
  num3 = num % (int)pow(10, position - 1);
  //now, we have a number only with first decimal place and 000 next
  algarism = num2 - num3;

  //deleting 000
  algarism /= (int)pow(10, position - 1);

  return algarism;
}
