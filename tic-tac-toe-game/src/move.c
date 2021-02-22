#include <stdio.h>
#include <stdlib.h>
#include "../include/move.h"
#include "../include/point.h"

typedef struct point {
  float x;
  float y;
} Point;

typedef struct move {
  Point movePoint;
  char moveValue;
} Move_t;

void setMove(Move_t *move, int x, int y, char value) {
  move->movePoint.x = x;
  move->movePoint.y = y;
  move->moveValue = value;
}

void getMove(Move_t *move, int *x, int *y, char *value) {
  *x = move->movePoint.x;
  *y = move->movePoint.y;
  *value = move->moveValue;
}

void freeMove(Move_t *move) {
  free(move);
}

int readMove(Move_t *move) {
  return (scanf("%f %f %c", &move->movePoint.x, &move->movePoint.y, &move->moveValue) == 3);
}

Move_t* createMove() {
  Move_t *move = (Move_t *) malloc(sizeof(Move_t));
  return move;
}