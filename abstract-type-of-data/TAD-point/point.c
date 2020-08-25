#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

struct point 
{
    float x;
    float y;
};

Point* create_point(float x, float y)
{
    Point* allocatedPoint;
    allocatedPoint = (Point*)malloc(sizeof(Point));

    if(allocatedPoint == NULL)
    {
        printf("Insufficient space!!");
        exit(1);
    }
    allocatedPoint->x = x;
    allocatedPoint->y = y;

    return allocatedPoint;
}

void free_point(Point* point)
{
    free(point);
}

void acess_point(Point* point, float* x, float* y)
{
    *x = point->x;
    *y = point->y;
}

void assign_point(Point* point, float x, float y)
{
    point->x = x;
    point->y = y;
}

float calculate_distance(Point* point1, Point* point2)
{
    float dx, dy, distance;

    dx = point2->x - point1->x;
    dy = point2->y - point1->y;

    distance = sqrt(pow(dx, 2) + pow(dy, 2));

    return distance;
}
