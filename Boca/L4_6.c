// Exercise: L4_6
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point
{
  int x;
  int y;
};
typedef struct point Point;

struct straight
{
  Point p1;
  Point p2;
};
typedef struct straight Straight;

float distancePoints(Point p1, Point p2);
void displayConditionPoint(Point p, Straight s);

int main(void)
{
  int i, qtd;
  Point point;
  Straight straight;

  scanf("%d", &qtd);

  for(i = 0; i < qtd; i++)
  {
    scanf("%d %d %d %d %d %d", &point.x, &point.y, &straight.p1.x, &straight.p1.y, &straight.p2.x, &straight.p2.y);
    displayConditionPoint(point, straight);
  }

  return 0;
}

float distancePoints(Point p1, Point p2)
{
  float distance, dx, dy;
  dx = p2.x - p1.x;
  dy = p2.y - p1.y;
  distance = sqrt(pow(dx, 2) + pow(dy, 2));
  return distance;
}

void displayConditionPoint(Point p, Straight s)
{
  float distanceUntilEnd, distanceUntilStart;

  distanceUntilStart = distancePoints(p, s.p1);
  distanceUntilEnd = distancePoints(p, s.p2);

  if(distanceUntilStart < distanceUntilEnd)
    printf("INICIO\n");
  else if(distanceUntilStart > distanceUntilEnd)
    printf("FIM\n");
  else
    printf("EQUIDISTANTE\n");
}