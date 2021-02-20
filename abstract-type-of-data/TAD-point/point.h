// exported structure
typedef struct point Point;
// function that sets values to a point
void setPoint(Point *point, float x, float y);
// function that returns a point in a x-y coordinate
void getPoint(Point *point, float *x, float *y);
// function that displays a pointt
void displayPoint(Point *point);
// function that releases a point
void freePoint(Point *point);
// function that calculates the distance between two given points
float calculateDistancePoints(Point *point1, Point *point2);
// function that creates new instances of a point
Point* createPoint(float x, float y);