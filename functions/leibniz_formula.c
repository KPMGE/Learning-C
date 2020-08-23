//Program that calculates an approximation to PI number, using the Leibniz formula

#include <stdio.h>
#include <math.h>

double pi(int number);

int main(void)
{
    int number;
    double approximationPi;

    printf("Type the number to the approximation: ");
    scanf("%d", &number);

    approximationPi = pi(number);

    printf("The approximation is: %.10g", approximationPi);

    return 0;
}

double pi(int n)
{
    int i;
    double approximationPi, summation = 0;

    for(i = 0; i < n; i++)
        summation += pow(-1, i) / (2 * i + 1);

    approximationPi = 4 * summation;

    return approximationPi;
}
