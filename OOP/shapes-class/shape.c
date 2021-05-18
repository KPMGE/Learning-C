#include "shape.h"

void ShapeConstructor(Shape_t* const self, int x, int y) {
	self->x = x;
	self->y = y;
}

void ShapeMoveBy(Shape_t* const self, int dx, int dy) {
	self->x += dx;
	self->y += dy;
}

int ShapeGetX(Shape_t* const self) {
	return self->x;
}

int ShapeGetY(Shape_t* const self) {
	return self->y;
}

