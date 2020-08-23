//Program that calculate the integer division among two numbers

#include <stdio.h>

void read_data(int* number1, int* number2);
int calculate_rest(int number1, int number2);

int main(void){
	int number1, number2, rest, choice;

    do
    {
        read_data(&number1, &number2);
        rest = calculate_rest(number1, number2);
        printf("The rest of integer division is: %d\n\n", rest);
        printf("Do you want to calculate again?\n");
        printf("Yes - any number\n NO - 0\n> ");
        scanf("%d", &choice);
    } while(choice != 0);

	return 0;
}

void read_data(int* number1, int* number2)
{
    printf("Type the first number: ");
    scanf("%d", number1);
    printf("Type the second number: ");
    scanf("%d", number2);
}

int calculate_rest(int number1, int number2)
{
    int rest;
    rest = number1 % number2;

    return rest;
}
