//Program that calculates the fibonnaci sequence

#include <stdio.h>

void print_fibonnaci(int number);

int main(void)
{
    int number;

    printf("How many numbers of the fibonnaci sequence do you want to calculate? ");
    scanf("%d", &number);

    print_fibonnaci(number);

    return 0;
}

void print_fibonnaci(int number)
{
    int i, sum = 0, previous = 0, next = 1;

    printf("%d ", 1);
    for(i = 0; i < (number-1); i++)
    {
        sum = previous + next;
        previous = next;
        next = sum;
        printf("%d ", sum);
        sum = 0;
    }
}
