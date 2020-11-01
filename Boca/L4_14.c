// Exercise: L4_14
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define True 1
#define False 0
#define PI 3.141592

typedef struct 
{
  float value1;
  float value2;
  float value3;
} geometricForms;

geometricForms readGeometricForm();
int isRectangle(geometricForms form);
int isSquare(geometricForms form);
int isCircle(geometricForms form);
float calculateAreaCircle(geometricForms circle);
float calculateAreaSquare(geometricForms square);
float calculateAreaRectangle(geometricForms rectangle);

int main(void)
{
  int qtdGeometricForms, i, qtdSquares = 0, qtdCircles = 0, qtdRectangles = 0;
  float totalAreaCircles = 0, totalAreaSquares = 0, totalAreaRectangles = 0;
  geometricForms someForm;

  scanf("%d", &qtdGeometricForms);

  for (i = 0; i < qtdGeometricForms; i++)
  {
    someForm = readGeometricForm();

    if (isCircle(someForm))
    {
      qtdCircles++;
      totalAreaCircles += calculateAreaCircle(someForm);
    }
    if (isRectangle(someForm))
    {
      qtdRectangles++;
      totalAreaRectangles += calculateAreaRectangle(someForm);
    }
    if (isSquare(someForm))
    {
      qtdSquares++;
      totalAreaSquares += calculateAreaSquare(someForm);
    }
  }

  printf("Circulos: %d Area: %.2f\n", qtdCircles, totalAreaCircles);
  printf("Quadrados: %d Area: %.2f\n", qtdSquares, totalAreaSquares);
  printf("Retangulos: %d Area: %.2f", qtdRectangles, totalAreaRectangles);

  return 0;
}

geometricForms readGeometricForm()
{
  geometricForms form;
  scanf("%f %f %f", &form.value1, &form.value2, &form.value3);
  return form;
}

int isRectangle(geometricForms form)
{
  return ((form.value3 < 0) && (form.value1 != form.value2)) ? True : False;
}

int isSquare(geometricForms form)
{
  return ((form.value3 < 0) && (form.value1 == form.value2)) ? True : False;
}

int isCircle(geometricForms form)
{
  return ((form.value1 < 0) && (form.value2 < 0)) ? True : False;
}

float calculateAreaCircle(geometricForms circle)
{
  return PI * pow(circle.value3, 2);
}

float calculateAreaSquare(geometricForms square)
{
  return pow(square.value1, 2);
}

float calculateAreaRectangle(geometricForms rectangle)
{
  return rectangle.value1 * rectangle.value2;
}