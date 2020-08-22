//a program that works with a structure to students

#include <stdio.h>

struct student
{
    char name[81];
    char registration[8];
    float p1;
    float p2;
    float p3;
};
typedef struct student Student;

float average_exams(float p1, float p2, float p3);

void read_data(int n, Student* class);

void show_results(int n, Student* class);

int main(void)
{
    int n;
    
    printf("Type the amount of students: ");
    scanf("%d", &n);
    
    Student class[n];

    read_data(n, class);

    show_results(n, class);
        
    return 0;
}

float average_exams(float p1, float p2, float p3)
{
    float average;

    average = (p1 + p2 + p3) / 3;

    return average;
}

void read_data(int n, Student* class)
{
    int i;

    printf("Type the value of P1: ");
    scanf("%f", &class->p1);

    printf("Type the value of P2: ");
    scanf("%f", &class->p2);

    printf("Type the value of P3: ");
    scanf("%f", &class->p3);

    for(i = 0; i < n; i++)
    {
        printf("Type the name of student: ");
        scanf("%s", class->name);

        printf("Type the registration: ");
        scanf("%s", class->registration);
    }
}

void show_results(int n, Student* class)
{
    int i;
    float average;

    average = average_exams(class->p1, class->p2, class->p3);
    printf("\nThe average is %.2f\n", average);

    for(i = 0; i < n; i++)
    {
        printf("Student %d\n", i);
        printf("Name: %s\n", class[i].name);
        printf("Registration: %s\n", class[i].registration);
    }
}

