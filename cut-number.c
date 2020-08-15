//import libraries
#include <stdio.h>
#include <math.h>

//function that return the size of nmber
int sizeNum(int num);

//function that return the position
int algarismNum(int num, int position);

int main(void)
{
    //declaring variables
    int num, size, algarism, i;

    //reading data
    printf("Type the number: ");
    scanf("%d", &num);
    
    //calculating number size
    size = sizeNum(num);

    //showing number's size
    printf("The number's size is: %d\n", size);

    //showing algarisms
    for(i = 1; i <= size; i++)
    {
        algarism = algarismNum(num, i);
        printf("The algarism in position: %d is %d\n", i, algarism);
    }

    return 0;
}

int sizeNum(int num)
{
    //declaring variables
    int rest, i=1, size = 0;

    //while rest different than num
    while(rest != num)
    {
        //rest is the rest of division between num and 10 to two
        rest = num % (int)pow(10, i);

        //incrementing size and i
        size++;
        i++;
    }
    
    return size;
}

int algarismNum(int num, int position)
{
    //declaring variables
    int algarism, num2, num3;

    //num2 is the integral number until the decimal place specified
    num2 = num % (int)pow(10, position);

    //num3 is a number minus one decimal place
    num3 = num % (int)pow(10, position-1);

    //algarism is num2 - num3, we have a number with 000... in ending
    algarism = num2 - num3;

    //cuting 000...
    algarism /= (int)pow(10, position-1);

    return algarism;
}
