#include <stdio.h>
#include <stdlib.h>

void drawSquare(int size);
void drawHorizonalLine(int amount);
void drawVerticalLines(int amount);
void putSpaces(int amount);

int main(void)
{
  int size;

  printf("Enter a size to draw rectangle: ");
  scanf("%d", &size);

  drawSquare(size);

  return 0;
}

void drawSquare(int size)
{
  drawHorizonalLine(size);
  drawVerticalLines(size);
  drawHorizonalLine(size);
}

void drawHorizonalLine(int amount)
{
  int i;
  for (i = 0; i < amount; i++)
  {
    printf("# ");
  }
}

void drawVerticalLines(int amount)
{
  int i;
  printf("\n");
  for (i = 0; i < amount; i++)
  {
    printf("#");
    putSpaces(2 * amount - 3);
    printf("#\n");
  }
}

void putSpaces(int amount)
{
  int i;
  for (i = 0; i < amount; i++)
  {
    printf(" ");
  }
}