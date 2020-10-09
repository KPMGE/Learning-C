#include <stdio.h>
#include <stdlib.h>

float sum(float num1, float num2);
float subtraction(float num1, float num2);
float division(float num1, float num2);
float multiplication(float num1, float num2);

int main(void)
{
  float num1, num2, num3, result;
  char operator;

  scanf("%f %f %c", &num1, &num2, &operator);
  switch (operator)
  {
    case '+':
      result = sum(num1, num2);
    break;

    case '-':
      result = subtraction(num1, num2);
    break;

    case '*':
      result = multiplication(num1, num2);
    break;

    case '/':
      result = division(num1, num2);
    break;
  }

  while (scanf("%f %c", &num3, &operator) == 2)
  {
    switch (operator)
    {
      case '+':
        result = sum(result, num3);
      break;

      case '-':
        result = subtraction(result, num3);
      break;

      case '*':
        result = multiplication(result, num3);
      break;

      case '/':
        result = division(result, num3);
      break;
    }
  }
  printf("%.2f", result);

  return 0; 
}

float sum(float num1, float num2)
{
  return num1 + num2;
}

float subtraction(float num1, float num2)
{
  return num1 - num2;
}

float division(float num1, float num2)
{
  return num1 / num2;
}

float multiplication(float num1, float num2)
{
  return num1 * num2;
}