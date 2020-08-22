//Program that reads a point and show it on screen, using structures
//
//OBS: Ever that a struct is used in a function, we must use a pointer to it
//
//OBS: we can acess the fields of a pointer to structure using: '(variavel->campo)'
//
//OBS: We can the memory's address with a pointer to structure using: '(&variavel->campo)'


//importing libraries
#include <stdio.h>

//defining structure to a point
struct point
{
    float x;
    float y;
};

//function that shows the point on screen
void show_point(struct point *p);

int main(void)
{
    //declaring variable p as a point
    struct point p;

    //defining a pointer to structure 
    struct point *pointer_to_point;

    //assigning variable's address
    pointer_to_point = &p;

    //reading point
    printf("Type any point: ");
    scanf("%f %f", &p.x, &p.y);

    //showing point
    show_point(pointer_to_point);

    return 0;
}

void show_point(struct point *pp)
{
    //showing point
    printf("The point is:  (%.2f, %.2f)", pp->x, pp->y);
}
