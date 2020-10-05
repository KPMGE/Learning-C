#include <stdio.h>
#include <stdlib.h>

//creating PI as a constant
const float PI = 3.14159;

int main(void)
{
  float radius, radius2, areaBigCircle, areaSmallCircle, grayArea;
  scanf("%f", &radius);

  areaSmallCircle = PI * radius * radius;
  //the circle 2 has a radius two times greater than circle 1
  radius2 = radius * 1.5;
  areaBigCircle = PI * radius2 * radius2;

  //calculating gray area
  grayArea = areaBigCircle - areaSmallCircle;

  printf("%.4f\n", grayArea);

  return 0;
}
