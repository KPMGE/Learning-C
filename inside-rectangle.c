//a program that checks if a point is inside of a rectangle, using stuctures

#include <stdio.h>
#include <stdlib.h>

struct point 
{
    float x;
    float y;
};

typedef struct point Point;

int inside_rectangle(Point* v1, Point* v2, Point* p);

int main(void)
{
    Point v1, v2, p;

    printf("Type the bottom left point: ");
    scanf("%f %f", &v1.x, &v1.y);

    printf("Type the bottom right point: ");
    scanf("%f %f", &v2.x, &v2.y);

    printf("Type any point: ");
    scanf("%f %f", &p.x, &p.y);
    
    if(inside_rectangle(&v1, &v2, &p))
        printf("\nInside of rectangle!");
    else
        printf("\nOutside of rectangle!");

    return 0;
}

int inside_rectangle(Point* v1, Point* v2, Point* p)
{
    if((p->x > v1->x) && (p->x < v2->x))
    {
        if((p->y > v1->y) && (p->y < v2->y))
            return 1;
    }
    else
        return 0;
}
