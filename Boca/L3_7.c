// Exercise: L3_7
// Author: Kevin Carvalho De Jesus

#include <stdio.h>
#include <stdlib.h>

int calculateTotalArea(int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2);
int calculateArea(int x1, int y1, int x2, int y2);

int main(void)
{
  int r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2;
  int totalArea;

  scanf("%d%d%d%d", &r1_x1, &r1_y1, &r1_x2, &r1_y2);
  scanf("%d%d%d%d", &r2_x1, &r2_y1, &r2_x2, &r2_y2);

  totalArea = calculateTotalArea(r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2);
  printf("RESP:%d", totalArea);
  return 0;
}

int calculateTotalArea(int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2)
{
  int area1, area2, area3 = 0, totalArea;

  area1 = calculateArea(r1_x1, r1_y1, r1_x2, r1_y2);
  area2 = calculateArea(r2_x1, r2_y1, r2_x2, r2_y2);

  if (r2_x1 < r2_x2 && r2_y1 < r1_y2)
    area3 = calculateArea(r2_x1, r2_y1, r1_x2, r1_y2);
  totalArea = area1 + area2 - area3;
  return totalArea;
}

int calculateArea(int x1, int y1, int x2, int y2)
{
  return (x2 - x1) * (y2 - y1);
}