//program that calculate all prime nunbers in open interval of n until m

//import libraries
#include <stdio.h>

//function that checks if number is prime 
int isPrime(int n);

int main(void){
    //declaring variables
	int n, m, choice=1, cont=0;

	do{
		//simple header
        printf("----------------------------------Calculating prime numbers in an interval-----------------------------------------\n\n");
		
		//reading data
        printf("Type two numbers for definition of interval: ");
		scanf("%d %d", &n, &m);

		//incrementing n, because the interval is open
		n++;

		for(n; n < m; n++){
            //if number 'n' is prime
			if(isPrime(n)){
                //showing prime number and incrementing 'cont'
				printf("~  %d\n", n);
				cont++;
			}
		}
		
		//showing the numbers amount in the interval
		printf("There are: %d prime numbers in this interval!!", cont);

		//asking if the user wants to calculate again 
		printf("\n\nDo you want to calcualte again?\nYes - AnyNumber\nNo - 0\n> ");
		scanf("%d", &choice);
	}while(choice != 0);

    return 0;
}

int isPrime(int n)
{
    //variables for comparison
    int i = 2, prime = 0;

    //if the number different than 1 or -1
    if (n != 1 && n != -1 && n != 0)
    {
        //if the number is negative
        if (n < 0)
        {
            //the variable i receives the value -2. The smaller prime number
            i = -2;

            while (n < i)
            {
                //if rest of division between n and i is 0
                if (n % i == 0)
                    prime++;

                //decrementing i
                i--;
            }

            //if variable prime to contniue with 0, it's a prime number
            return (prime == 0) ? 1 : 0;
        }
        //if number positive
        else
        {
            while (i < n)
            {
                //if rest of division between n and i is 0
                if (n % i == 0)
                    prime++;

                //incrementing variable i
                i++;
            }

            //if variable prime to contniue with 0, it's a prime number
            return (prime == 0) ? 1 : 0;
        }
    }
    //if number is 1 or -1, it isn't a prime number
    else
        return 0;
}
