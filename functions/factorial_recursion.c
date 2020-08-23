//Program that calculates the factorial of a number, using recursive functions

#include <stdio.h>

int calculate_factorial(int number);

int main(void)
{
    int number, factorial;

    printf("Type the number: ");
    scanf("%d", &number);

    factorial = calculate_factorial(number);

    printf("factorial: %d", factorial);

    return 0;
}

int calculate_factorial(int number)
{
    if(number == 0)
        return 1;
    else
        return calculate_factorial(number - 1) * number;
}
