#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int number, elements, n1, n2, n3, n4, n5, n6, n7, n8, n9, i;
  char letter;

  scanf("%d", &elements);

  for (i = 1; i <= elements; i++)
  {
    scanf("%d", &number);
    if (i == 1)
      n1 = number;
    if (i == 2)
      n2 = number;
    if (i == 3)
      n3 = number;
    if (i == 4)
      n4 = number;
    if (i == 5)
      n5 = number;
    if (i == 6)
      n6 = number;
    if (i == 7)
      n7 = number;
    if (i == 8)
      n8 = number;
    if (i == 9)
      n9 = number;
  }

  i = 0;
  scanf("%c", &letter);
  while (i != 2)
  {
    scanf("%c", &letter);
    if (letter == '"')
      i++;
    if (letter == '%')
    {
      scanf("%d", &number);
      if (number > elements || number < 1)
        printf("ERRO");
      else if (number == 1)
        printf("%d", n1);
      else if (number == 2)
        printf("%d", n2);
      else if (number == 3)
        printf("%d", n3);
      else if (number == 4)
        printf("%d", n4);
      else if (number == 5)
        printf("%d", n5);
      else if (number == 6)
        printf("%d", n6);
      else if (number == 7)
        printf("%d", n7);
      else if (number == 8)
        printf("%d", n8);
      else if (number == 9)
        printf("%d", n9);
    }
    else if (letter != '"')
      printf("%c", letter);
  }
  return 0;
}
