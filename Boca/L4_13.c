// Exercise: L4_13
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

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

int main(void)
{
  int qtdGeometricForms, i, qtdSquares = 0, qtdCircles = 0, qtdRectangles = 0;
  geometricForms someForm;

  scanf("%d", &qtdGeometricForms);

  for (i = 0; i < qtdGeometricForms; i++)
  {
    someForm = readGeometricForm();
    if (isCircle(someForm))
      qtdCircles++;
    if (isRectangle(someForm))
      qtdRectangles++;
    if (isSquare(someForm))
      qtdSquares++;
  }

  printf("Circulos: %d\nQuadrados: %d\nRetangulos: %d", qtdCircles, qtdSquares, qtdRectangles);

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