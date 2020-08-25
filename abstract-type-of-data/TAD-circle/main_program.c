//Program that calculates the area of a circle and checks if a point given is inside of it

#include <stdio.h>
#include <math.h>
#include "point.h"
#include "circle.h"

int main(void)
{
    float areaCircle, x, y, radius;
    float x2, y2;
    Point* point;
    Circle* circle;

    printf("Type a circle: (x, y, radius): ");
    scanf("%f %f %f", &x, &y, &radius);
    printf("Type a point: ");
    scanf("%f %f", &x2, &y2);

    point = create_point(x2, y2);
    circle = create_circle(x, y, radius);
    areaCircle = area_circle(circle);

    printf("The area of this circle is: %.2f\n", areaCircle);
    if(inside_circle(circle, point))
        printf("The point typed is inside of circle!!");
    else
        printf("The point typed isn't inside of circle!!");

    free_point(point);
    free_circle(circle);
    return 0;
}
