//Simple program that uses vectors to structures

#include <stdio.h>

struct point
{
    float x; 
    float y;
};
typedef struct point Point;

void read_data(Point* vectorPoints);
void print_data(Point* vectorPoints);

int main(void)
{
    Point vectorPoints[5];

    read_data(vectorPoints);
    print_data(vectorPoints);

    return 0;
}

void read_data(Point* vectorPoints)
{
    int i;
    printf("Type 5 points (x, y):\n");

    for(i = 0; i < 5; i++)
        scanf("%f %f", &vectorPoints[i].x, &vectorPoints[i].y);
}

void print_data(Point* vectorPoints)
{
    int i;
     
    printf("Points:\n");
    for(i = 0; i < 5; i++)
        printf("(%.2f, %.2f)\n", vectorPoints[i].x, vectorPoints[i].y);
}

