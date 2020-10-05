/*
(BOCA:L2_18)
 Problema: Com dificuldade para estudar Álgebra Linear,
Padi decidiu fixar os conceitos da disciplina fazendo programas de
computador com a matéria. Para começar, quis fazer um programa
que, dado o tamanho da matriz e seus valores, que nunca são iguais,
calculasse o maior valor e imprimisse a posição dele na matriz.
Também com dúvidas em Programação, Padi agora pede sua ajuda e
você deve implementar o código para depois tirar as dúvidas do código
dele.

Entrada: uma linha com os valores L (1 <= L <= 100) e C (1 <= C <=
100), representando o tamanho da matriz em linhas e colunas,
respectivamente. Depois, L linhas com C valores V (-32767 <= V <=
32767) cada.

Saída: o maior valor V da matriz, seguido
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int row, column;
  int value, greatestValue = -32767, greatestRow, greatestColumn;

  scanf("%d %d", &row, &column);

  int i, j;
  for(i = 1; i <= row; i++)
  {
    for(j = 1; j <= column; j++)
    {
      scanf("%d", &value);
      if(value > greatestValue)
      {
        greatestValue = value;
        greatestRow = i;
        greatestColumn = j;
      }
    }
  }

  printf("%d (%d, %d)", greatestValue, greatestRow, greatestColumn);

  return 0;
}