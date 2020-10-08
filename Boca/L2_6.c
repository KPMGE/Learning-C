#include <stdio.h>
#include <math.h>

int main(void)
{
  int choice;
  scanf("%d", &choice);
  double sum = 0, i = 1, j = 1;

  switch (choice)
  {
    case 1:
      for (i; i <= 50; i++, j += 2)
        sum += j / i;

      printf("%f", sum);
    break;

    case 2:
      i = 50;
      for (j; j <= 50; j++, i--)
        sum += pow(2, j) / i;
      printf("%f", sum);
    break;

    case 3:
      for (j; j <= 10; j++, i++)
        sum += j / pow(i, 2);
      printf("%f", sum);
    break;
  }

  return 0;
}
