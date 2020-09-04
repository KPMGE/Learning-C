//Progam that transforms the elements from matrix in prime elements

//import libraries
#include <stdio.h>

//function that checks if the number is prime
int isPrime(int n);

//function that transforms the number for next prime
int transformPrime(int n);

int main(void)
{
    //declaring variables
    int row, column, i, j;

    //reading matrix size
    printf("Type the rows and columns for matrix: ");
    scanf("%d %d", &row, &column);

    //declaring matrix with seted size
    int matrix[row][column], matrixResult[row][column];

    //reading matrix
    printf("Type the matrix: \n");
    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            scanf("%d", &matrix[i][j]);

    //calculating matriz result
    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            matrixResult[i][j] = transformPrime(matrix[i][j]);

    //showing matrix result
    printf("\n\nMatrix result:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("%d ", matrixResult[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int isPrime(int n)
{
    if((n == 0) || (n == 1) || (n == -1))
        return 0;

    if(n > 0)
    {
        for(int i = 2; i < n; i++)
        {
            if(n % i == 0)
                return 0;
        }
        return 1;
    }
    else
    {
        for(int i = -2; i > n; i--)
        {
            if(n % i == 0)
                return 0;
        }
        return 1;
    }
}

int transformPrime(int n)
{
    //the smaller positive prime number 
    int i;

    //if number already is prime, just return it 
    if (isPrime(n))
        return n;

    //transform to next negative prime number
    if (n < 0)
    {
        //variable with the smaller negative prime number
        i = n;

        while (1)
        {
            //if i less than n
            if (i < n)
            {
                //checking if i is a prime number, if yes, return it
                if (isPrime(i))
                    return i;
            }

            //decrementing i
            i--;

            //if number is bigger than 32000
            if (i > 32000)
                return n;
        }
    }

    else
    {
        i = n;

        while(1)
        {
            //if i bigger than n
            if(i > n)
            {
                //checking if i is a prime number, if yes, return it
                if(isPrime(i))
                    return i;
            }

            //incrementing i
            i++;

            //if number id bigger than 32000
            if(i > 32000)
                return n;
        }
    }
}
