#include <stdio.h>
#include "point.h"

int main(void)
{
    float x1, y1, x2, y2, distance;

    printf("Type a point (x, y): ");
    scanf("%f %f", &x1, &y1);
    printf("Type other point (x, y): ");
    scanf("%f %f", &x2, &y2);

    Point* point1 = create_point(x1, y1);
    Point* point2 = create_point(x2, y2);

    distance = calculate_distance(point1, point2);

    printf("The distance among the points is: %f", distance);

    free_point(point1);
    free_point(point2);

    return 0;
}
