#include "point.h"

//name for struct circle
typedef struct circle Circle;

//function that allocates and creates a circle with center in (x, y)
Circle* create_circle(float x, float y, float radius);

//function that releses the memory allocated by a circle
void free_circle(Circle* circle);

//function that returns the area of circle
float area_circle(Circle* circle);

//function that verificates if a point is inside of a circle
int inside_circle(Circle* circle, Point* point);
