#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/point.h"

typedef struct point {
  float x;
  float y;
} Point;

void setPoint(Point *point, float x, float y) {
  point->x = x;
  point->y = y;
}

void getPoint(Point *point, float *x, float *y) {
  *x = point->x;
  *y = point->y;
}

void displayPoint(Point *point) {
  printf("(%.2f, %.2f)\n", point->x, point->y);
}

void freePoint(Point *point) {
  free(point);
}

Point* createPoint(float x, float y) {
  Point *point = (Point*)malloc(sizeof(Point));

  if (point == NULL) {
    printf("invalid pointer!");
    exit(1);
  } 

  point->x = x;
  point->y = y;

  return point;
}
