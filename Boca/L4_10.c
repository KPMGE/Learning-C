// exercise: L4_10
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
  float x;
  float y;
} Point;

float distancePoints(Point point1, Point point2);
void displayPoint(Point point);

int main(void)
{
  int qtdPoints, i;
  float smallestDistance = 0;
  Point point, firstPoint, nearPoint;

  scanf("%d", &qtdPoints);
  scanf("%f %f", &firstPoint.x, &firstPoint.y);

  for (i = 1; i < qtdPoints; i++)
  {
    scanf("%f %f", &point.x, &point.y);

    if (i == 1)
    {
      smallestDistance = distancePoints(firstPoint, point);
      nearPoint = point;
    }

    else if (distancePoints(firstPoint, point) < smallestDistance)
    {
      smallestDistance = distancePoints(firstPoint, point);
      nearPoint = point;
    }
  }

  displayPoint(nearPoint);

  return 0;
}

float distancePoints(Point point1, Point point2)
{
  float distance, dx, dy;
  dx = point2.x - point1.x;
  dy = point2.y - point1.y;
  distance = sqrt(pow(dx, 2) + pow(dy, 2));
  return distance;
}

void displayPoint(Point point)
{
  printf("Mais proximo:(%.f,%.f)", point.x, point.y);
}