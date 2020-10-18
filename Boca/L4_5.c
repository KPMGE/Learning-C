// Exercise: L4_5
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point
{
  float x;
  float y;
};
typedef struct point Point;

float distancePoints(Point p1, Point p2);

int main(void)
{
  int i, qtdpoints;
  Point currentPoint, previousPoint;

  scanf("%d", &qtdpoints);

  scanf("%f %f", &currentPoint.x, &currentPoint.y);
  printf("-\n");
  previousPoint.x = currentPoint.x;
  previousPoint.y = currentPoint.y;

  for(i = 1; i < qtdpoints; i++)
  {
    scanf("%f %f", &currentPoint.x, &currentPoint.y);
    printf("%.2f\n", distancePoints(currentPoint, previousPoint));

    previousPoint.x = currentPoint.x;
    previousPoint.y = currentPoint.y;
  }

  return 0;
}

float distancePoints(Point p1, Point p2)
{
  float distance, dx, dy;

  dx = p2.x - p1.x;
  dy = p2.y - p1.y;
  distance = sqrt(pow(dx, 2) + pow(dy, 2)) ;

  return distance;
}