// Exercise: L4_4
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

struct Point
{
  int x;
  int y;
};
typedef struct Point Point;

int quadrantPoint(Point p);
Point symmetricPoint(Point p);

int main(void)
{
  int i, qtdPoints;
  Point point, symmetric;

  scanf("%d", &qtdPoints);

  for(i = 0; i < qtdPoints; i++)
  {
    scanf("%d %d", &point.x, &point.y);
    symmetric = symmetricPoint(point);
    printf("(%d,%d) %d (%d,%d) %d\n", point.x, point.y, quadrantPoint(point), symmetric.x, symmetric.y, quadrantPoint(symmetric));
  }

  return 0;
}

int quadrantPoint(Point p)
{
  if((p.x == 0) || (p.y == 0))
    return 0;
    
  if((p.x > 0) && (p.y > 0))
    return 1;

  if((p.x < 0) && (p.y > 0))
    return 2;

  if((p.x < 0) && (p.y < 0))
    return 3;
  
  if((p.x > 0) && (p.y < 0))
    return 4;
}

Point symmetricPoint(Point p)
{
  Point symmetric;
  symmetric.x = -p.x;
  symmetric.y = -p.y;
  return symmetric;
}