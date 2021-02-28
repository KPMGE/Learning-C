// convert from and to polar/cartesian coordinates

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void convertToPolarCoordinate(float x, float y);
void convertToCartesianCoordinate(float r, float theta);

int main(void) {
  int choice;
  float value1, value2;

  printf("Enter point coordinates: ");
  scanf("%f %f", &value1, &value2);

  printf("\ndo you want to convert to? \n\n");
  printf("1 - polar coordinate\n");
  printf("2 - cartesian coordinate\n> ");
  scanf("%d", &choice);

  switch(choice) {
    case 1: 
      convertToPolarCoordinate(value1, value2);
      break;

    case 2: 
      convertToCartesianCoordinate(value1, value2);
      break;

    default: 
      printf("error");
      break;
  }

  return 0;
}

void convertToPolarCoordinate(float x, float y) {
  float r, theta;

  r = sqrt(pow(x, 2) + pow(y, 2));
  theta = atan(y / x);

  printf("Your polar coordinate is: (%.2f, %.2f)", r, theta);
}

void convertToCartesianCoordinate(float r, float theta) {
  float x, y;

  x = r * cos(theta);
  y = r * sin(theta);

  printf("Your cartesian point is: (%.2f, %.2f)", x, y);
}
