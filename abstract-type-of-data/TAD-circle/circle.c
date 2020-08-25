//program with the functions for the circles

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "circle.h"

#define PI 3.14159

struct circle
{
    Point* center;
    float radius;
};

Circle* create_circle(float x, float y, float radius)
{
    Circle* allocatedCircle;

    allocatedCircle = (Circle*)malloc(sizeof(Circle));
    allocatedCircle->center = create_point(x, y);
    allocatedCircle->radius = radius;

    return allocatedCircle;
}

void free_circle(Circle* circle)
{
    free_point(circle->center);
    free(circle);
}

float area_circle(Circle* circle)
{
    float area;

    area = PI * pow(circle->radius, 2);

    return area;
}

int inside_circle(Circle* circle, Point* point)
{
    float distanceCenter;

    distanceCenter = calculate_distance(circle->center, point);

    return (distanceCenter < circle->radius) ? 1 : 0;
}
