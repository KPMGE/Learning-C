//program that calculate all prime nunbers in open interval of n until m

#include <stdio.h>

int isPrime(int n);

int main(void){
  int n, m, choice=1, cont=0;

	do{

    printf("----------------------------------Calculating prime numbers in an interval-----------------------------------------\n\n");
		
    printf("Enter two numbers for definition of interval: ");
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
  int i;

  if (n != 1 && n != -1 && n != 0)
  {
    if (n < 0)
    {
      for(i = -2; i >= n/2; i-- )
      {
          if (n % i == 0)
              return 0;
      }
      return 1;
    }
    else
    {
      for(i = 2; i <= n/2; i++)
      {
          if (n % i == 0)
              return 0;
      }
      return 1;
    }
  }
  else
    return 0;
}
