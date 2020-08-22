//Progaram that finds the multiple of each number in an interval
//
#include <stdio.h>

int main(void){
    int m, n, i=2, multi;

    printf("Type a interval: ");
    scanf("%d %d", &n, &m);

    for(n; n < m; n++)
    {
        printf("Number - %d\n", n);

        while(1)
        {
            multi = n*i;

            if(multi > m)
                break;
            else
                printf("multiple - %d\n", multi);
            
            i++;
        }

        printf("\n");
        i = 2;
    }

    return 0;
}
