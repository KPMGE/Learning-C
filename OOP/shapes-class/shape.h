#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED


typedef struct _virtualTable ShapeVirtualTable;

// shape's attributes
typedef struct {
	ShapeVirtualTable const *virtualTable;
	int x;
	int y;
} Shape_t;

// function pointers
typedef int (*areaFunc)(Shape_t const* const self);
typedef void (*drawFunc)(Shape_t const* const self);

struct _virtualTable {
	areaFunc calculateArea;
	drawFunc drawSomething;
};

// shapes's operations
void ShapeConstructor(Shape_t* const self, int x, int y);
void ShapeMoveBy(Shape_t* const self, int dx, int dy);
int ShapeGetX(Shape_t* const self);
int ShapeGetY(Shape_t* const self);

#endif
