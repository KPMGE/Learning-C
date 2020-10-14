#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float delta(float a, float b, float c);

int main(void)
{
  float  a, b, c, x1, x2, dt;
  scanf("%f %f %f", &a, &b, &c);

  dt = delta(a, b, c);

  if(dt < 0)
    printf("Nao ha raizes reais");
  else
  {
    x1 = (-b + sqrt(dt)) / (2 * a);
    x2 = (-b - sqrt(dt)) / (2 * a);
    printf("x1: %.2f x2: %.2f", x1, x2);
  }

  return 0;
}

float delta(float a, float b, float c)
{
  float delta;
  delta = pow(b, 2) - (4 * a * c);
  return delta;
}