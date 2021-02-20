#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main(void) {
  // create two points
  Point *p1 = createPoint(0, 0);
  Point *p2 = createPoint(2, 2);

  // displaying points and distance
  printf("Points:\n");
  printf("p1: ");
  displayPoint(p1);
  printf("p2: ");
  displayPoint(p2);
  printf("\n");
  printf("The distance between points is: %.2f\n", calculateDistancePoints(p1, p2));

  // set new value to point1
  setPoint(p1, 3, 3);
  printf("define new value to p1: ");
  displayPoint(p1);
  printf("\n");
  printf("The distance between now points is: %.2f", calculateDistancePoints(p1, p2));

  // releasing allocated memory
  freePoint(p1);
  freePoint(p2);

  return 0;
}
