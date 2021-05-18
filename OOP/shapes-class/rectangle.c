#include "rectangle.h"

void RectangleConstructor(Rectangle_t* self, int x, int y,  int width, int height) {
	ShapeConstructor(&self->super, x, y);
	self->width = width;
	self->height = height;
}

int RectangleGetWidth(Rectangle_t* self) {
	return self->width;
}

int RectangleGetHeight(Rectangle_t* self) {
  return self->height;
}
