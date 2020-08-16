//Progaram that finds the multiple of each number in an interval
//
//import libraries
#include <stdio.h>

int main(void){
    //declaring variables
    int m, n, i=2, multi;

    //reading data
    printf("Type a interval: ");
    scanf("%d %d", &n, &m);

    //loop of n until m
    for(n; n < m; n++)
    {
        //showing number
        printf("Number - %d\n", n);

        //showing multiple
        while(1)
        {
            //calculating multiple
            multi = n*i;

            //if multiple is bigger than m, ending loop
            if(multi > m)
                break;
            else
                printf("multiple - %d\n", multi);
            
            //incrementing variable i
            i++;
        }

        printf("\n");
        //reseting variable i
        i = 2;
    }

    return 0;
}
