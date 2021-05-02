// simple sample of function dispatch tables 
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

// pointer to functions that receive two doubles and return a double one
typedef double (*fptrMathOperation)(double num1, double num2);

// simple math operation functions
double sum(double num1, double num2); 
double sub(double num1, double num2); 
double multi(double num1, double num2); 
double divide(double num1, double num2); 

// array with our operations
fptrMathOperation operations[4] = {
  sum, 
  sub,
  multi,
  divide
};

int main(void) {
  int choice;
  double num1, num2;

  printf("Enter two numbers: ");
  scanf("%lf %lf", &num1, &num2);

  printf("Which operation do you want to do?\n");
  printf("0 - sum\n");
  printf("1 - subtraction\n");
  printf("2 - multiplication\n");
  printf("3 - division\n");
  scanf("%d", &choice);

  printf("Outcome: %.3f", operations[choice](num1, num2));


  return 0;
}

double sum(double num1, double num2) {
  return num1 + num2;
}

double sub(double num1, double num2) {
  return num1 - num2;
}

double multi(double num1, double num2) {
  return num1 * num2;
}

double divide(double num1, double num2) {
  return num1 / num2;
}
