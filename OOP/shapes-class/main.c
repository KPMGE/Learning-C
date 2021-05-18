#include <stdio.h>
#include <stdlib.h>
#include "shape.h"
#include "rectangle.h"

int main(void) {
	// implementation for shape
	
	// create an instance of a shape
	Shape_t s1;

	// initialize it
	ShapeConstructor(&s1, 2, 3);

	// display initial position
	printf("------ SHAPE ---- \n\n");
	printf("Shape's initial position: ");
	printf("(%d %d)\n", ShapeGetX(&s1), ShapeGetY(&s1));

	// change position
	ShapeMoveBy(&s1, 3, 5);

	// display final position
	printf("Shape's final position: ");
	printf("(%d, %d)\n", ShapeGetX(&s1), ShapeGetY(&s1));


	// implementation for rectangle
	
	// create two reactangles
	Rectangle_t rect1;

	// initialize them
	RectangleConstructor(&rect1, 1, 3, 4, 4);

	printf("\n\n------ RECTANGLES ---- \n\n");

	printf("Initial rectangle: ");
	printf("(%d, %d), width: %d, height: %d\n", ShapeGetX(&rect1.super), ShapeGetY(&rect1.super), RectangleGetWidth(&rect1), RectangleGetHeight(&rect1));

	// changing rectangle's coordinates
	ShapeMoveBy(&rect1.super, 0, 0);

	printf("Final rectangle: ");
	printf("(%d, %d), width: %d, height: %d", ShapeGetX(&rect1.super), ShapeGetY(&rect1.super), RectangleGetWidth(&rect1), RectangleGetHeight(&rect1));

	return 0;
}
