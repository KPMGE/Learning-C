// Exercise: P1_2018_Q1
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
  int x;
  int y;
} Point;

void displayRectangle(Point P, Point Q);

int main(void)
{
  Point P, Q;
  scanf("%d %d %d %d", &P.x, &P.y, &Q.x, &Q.y);
  displayRectangle(P, Q);

  return 0;
}

void displayRectangle(Point P, Point Q)
{
  if((P.x == P.y && Q.x == Q.y) && P.x < Q.x)
    printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n", P.x, Q.y, P.x, P.y, Q.x, P.y, Q.x, Q.y);
  else if(P.x < Q.x && P.y > Q.y)
    printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n", P.x, P.y, P.x, Q.y, Q.x, Q.y, Q.x, P.y);
  else if(P.x > Q.x && P.y < Q.y)
    printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n", Q.x, P.x, Q.x, P.y, P.x, Q.x, P.x, Q.y);
  else 
    printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n", Q.y, P.y, Q.x, Q.x, P.x, Q.y, P.x, P.y);
}