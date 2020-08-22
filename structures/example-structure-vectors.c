//program that reads ten points and after, prints it on screen

#include <stdio.h>

struct point
{
    float x;
    float y;
};
typedef struct point Point;

void read_data(Point *vectorPoints);
void print_data(Point *vectorPoints);

int main(void)
{
    Point vectorPoints[10];

    read_data(vectorPoints);
    print_data(vectorPoints);

    return 0;
}

void read_data(Point *vectorPoints)
{
    int i;

    for(i = 0; i < 10; i++)
    {
        printf("Type a point: ");
        scanf("%f %f", &vectorPoints[i].x, &vectorPoints[i].y);
    }
}

void print_data(Point *vectorPoints)
{
    int i;
    printf("----------------------Points-------------------\n");
    for(i = 0; i < 10; i++)
        printf("Point%d: (%.2f, %.2f)\n", (i+1), vectorPoints[i].x, vectorPoints[i].y);
}
