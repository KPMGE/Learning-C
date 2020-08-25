//TAD point: (x, y)

//type exported
typedef struct point Point;

//Exported functions

//function that alocates and returns a poins in the coordinates x, y
Point* create_point(float x, float y);

//function that frees the memory allocated by a point
void free_point(Point* point);

//functions that returns a value of a point in a x, y coordinate
void acess_point(Point* point, float* x, float* y);

//function that atributes a new value for a point in the x, y coordinate
void assign_point(Point* point, float x, float y);

//function that calculates and returns the distance between the point1 and point2
float calculate_distance(Point* point1, Point* point2);
