#include <stdio.h>

float sum(float num1, float num2);
float subtraction(float num1, float num2);
float division(float num1, float num2);
float multiplication(float num1, float num2); 

int main(void)
{
  float number1, number2;
  char operator;

  printf("enter a number + a operator + a second number: ");
  while(scanf("%f %c %f", &number1, &operator, &number2) == 3)
  {
    switch(operator)
    {
      case '+':
        printf("%.2f + %.2f = %.2f\n", number1, number2, sum(number1, number2));
      break;

      case '-':
        printf("%.2f - %.2f = %.2f\n", number1, number2, subtraction(number1, number2));
      break;

      case '/':
        printf("%.2f / %.2f = %.2f\n", number1, number2, division(number1, number2));
      break;

      case '*':
        printf("%.2f * %.2f = %.2f\n", number1, number2, multiplication(number1, number2));
      break;

    default:
      printf("Invalid operator\n");
    }
    printf("enter a number + a operator + a second number: ");
  }
  printf("you entered with invalid values!!");

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
