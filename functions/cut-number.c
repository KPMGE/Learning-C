#include <stdio.h>
#include <math.h>

int sizeNum(int number);
int algarismNum(int number, int position);

int main(void)
{
    int number, size, algarism, i;

    printf("Type the numberber: ");
    scanf("%d", &number);
    
    size = sizeNum(number);

    printf("The numberber's size is: %d\n", size);
    for(i = 1; i <= size; i++)
    {
        algarism = algarismNum(number, i);
        printf("The algarism in position: %d is %d\n", i, algarism);
    }

    return 0;
}

int sizeNum(int number)
{
    int rest, i=1, size = 0;

    while(rest != number)
    {
        rest = number % (int)pow(10, i);

        size++;
        i++;
    }
    
    return size;
}

int algarismNum(int number, int position)
{
    int algarism, number2, number3;

    number2 = number % (int)pow(10, position);
    number3 = number % (int)pow(10, position-1);
    algarism = number2 - number3;
    algarism /= (int)pow(10, position-1);

    return algarism;
}
