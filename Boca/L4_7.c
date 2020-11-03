// Exercise: L4_7
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef struct
{
  float x;
  float y;
} Point;

typedef struct 
{
  Point start;
  Point end;
} Straight;

Straight readStraight();
int isOnSameQuadrant(Straight straight);
int quadrantPoint(Point point);

int main(void)
{
  Straight straight;
  int n, i;

  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    straight = readStraight();

    if (isOnSameQuadrant(straight))
      printf("MESMO\n");
    else
      printf("DIFERENTE\n");
  }

  return 0;
}

Straight readStraight()
{
  Straight straight;
  scanf("%f %f %f %f", &straight.start.x, &straight.start.y, &straight.end.x, &straight.end.y);
  return straight;
}

int quadrantPoint(Point point)
{
  if (point.x > 0 && point.y > 0)
    return 1;
  if (point.x < 0 && point.y > 0)
    return 2;
  if (point.x < 0 && point.y < 0)
    return 3;
  if (point.x > 0 && point.y < 0)
    return 4;
}

int isOnSameQuadrant(Straight straight)
{
  if (straight.start.x == 0 || straight.start.y == 0 || straight.end.x == 0 || straight.end.y == 0)
    return False;
  if (quadrantPoint(straight.start) == quadrantPoint(straight.end))
    return True;
  else
    return False;
}