#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "shape.h"

typedef struct {
	Shape_t super; // inherits Shape class

	int width;
	int height;
} Rectangle_t;

void RectangleConstructor(Rectangle_t* self, int x, int y,  int width, int height);
int RectangleGetWidth(Rectangle_t* self);
int RectangleGetHeight(Rectangle_t* self);

#endif
