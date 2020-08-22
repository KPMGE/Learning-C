//Program that calculates the average of the grades, using dynamic allocation

//import libraries
#include <stdio.h>
#include <stdlib.h>

//function that returns the average
float calculate_average(int *grades, int amount);

int main(void)
{
    int amount, *grades;
    float averageGrades;

    //reading the amount of grades
    printf("Type the amout of grades: ");
    scanf("%d", &amount);

    //OBS: Now, we can work with 'grades' like a normal vector
    grades = (int *)malloc(amount*sizeof(int));

    //if there is no space for allocation
    if(grades == NULL)
    {
        printf("Insufficient space!!");
        return 1;
    }

    //reading grades
    for(int i = 0; i < amount; i++)
    {
        printf("Type the grade %d: ", i+1);
        scanf("%d", &grades[i]);
    }

    //calculating average
    averageGrades = calculate_average(grades, amount);

    //showing results
    printf("The average of grades is: %.2f", averageGrades);

    //releasing memory
    free(grades);

    return 0;
}

float calculate_average(int *grades, int amount)
{
    int sum = 0;

    for(int i = 0; i < amount; i++)
        //incrementing grades
        sum += grades[i];

    //returning average
    return sum / (float)amount;
}
