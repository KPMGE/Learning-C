//program that calculate all prime nunbers in open interval of n until m

#include <stdio.h>

int isPrime(int n);

int main(void){
	int n, m, choice=1, cont=0;

	do{
        printf("----------------------------------Calculating prime numbers in an interval-----------------------------------------\n\n");
		
        printf("Type two numbers for definition of interval: ");
		scanf("%d %d", &n, &m);

		n++;

		for(n; n < m; n++){
			if(isPrime(n)){
				printf("~  %d\n", n);
				cont++;
			}
		}
		
		printf("There are: %d prime numbers in this interval!!", cont);

		printf("\n\nDo you want to calcualte again?\nYes - AnyNumber\nNo - 0\n> ");
		scanf("%d", &choice);
	}while(choice != 0);

    return 0;
}

int isPrime(int n)
{
    int i = 2, prime = 0;

    if (n != 1 && n != -1 && n != 0)
    {
        if (n < 0)
        {
            i = -2;

            while (n < i)
            {
                if (n % i == 0)
                    prime++;

                i--;
            }

            return (prime == 0) ? 1 : 0;
        }
        else
        {
            while (i < n)
            {
                if (n % i == 0)
                    prime++;

                i++;
            }

            return (prime == 0) ? 1 : 0;
        }
    }
    else
        return 0;
}
