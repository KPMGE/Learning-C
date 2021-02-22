// functions for tic-tac-toe game

#include "move.h"
#include "point.h"
// function that displays a table
void displayTable(char **table);
// function that set new values for table
void setMovePlayer(char **table, Move_t *movePlayer);
// function that reads a move
void readMovePlayer(int player, Move_t *movePlayer);
// function that releases a table
void freeTable(char **table);
// function that checks the coordinate of the point
int checkPoint(Point *point);
// function that checks columns of the table
int checkColumns(char **table);
// function that checks lines of the table
int checkLines(char **table);
// function that creates a table for game
char** createTable();
