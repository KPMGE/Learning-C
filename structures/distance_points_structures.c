//Program that calculates the distance among two point, using structures

#include <stdio.h>
#include <math.h>

struct point
{
    float x;
    float y;
};

float calculate_distance(struct point* point1, struct point* point2);
void read_points(struct point* point1, struct point* point2);

int main(void)
{
    float distancePoints;
    struct point point1, point2;
    
    read_points(&point1, &point2);

    distancePoints = calculate_distance(&point1, &point2);

    printf("The distance between the point1 and point2 is: %.2f", distancePoints);

    return 0;
}

void read_points(struct point* point1, struct point* point2)
{
    printf("Enter a point 1: ");
    scanf("%f %f", &point1->x, &point1->y);
    printf("Enter a point 2: ");
    scanf("%f %f", &point2->x, &point2->y);
}

float calculate_distance(struct point* point1, struct point* point2)
{
    float distance, deltax, deltay;

    deltax = point2->x - point1->x;
    deltay = point2->y - point1->y;
    distance = sqrt(pow(deltax, 2) + pow(deltay, 2));

    return distance;
}
