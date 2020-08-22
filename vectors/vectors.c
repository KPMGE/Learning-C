//program that calculates the average of a amount grades, using vectors 
//
//import libraries
#include <stdio.h>

int main(void)
{
    //declaring variables
    int qtd, i, sum = 0;
    float average;

    //reading the amount grades
    printf("Type the amount of grades: ");
    scanf("%d", &qtd);

    //declaring a vector for grades
    int grades[qtd];

    for(i = 0; i < qtd; i++)
    {
        //reading grades
        printf("Type the %d grade: ", i+1);
        scanf("%d", &grades[i]);

        //incrementing sum
        sum += grades[i];
    }

    //calculating average
    average = sum / (float)qtd;

    //showing results
    printf("The average is: %.2f", average);
    return 0;
}
