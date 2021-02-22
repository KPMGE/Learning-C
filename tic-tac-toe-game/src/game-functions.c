#include <stdio.h>
#include <stdlib.h>
#include "../include/point.h"
#include "../include/move.h"
#include "../include/game-functions.h"

typedef struct point {
  float x;
  float y;
} Point;

typedef struct move {
  Point movePoint;
  char moveValue;
} Move_t;

#define TRUE 1
#define FALSE 0
#define SIZE_LINE_TABLE 3 
#define SIZE_COLUMN_TABLE 5 

void displayTable(char **table) {
  system("clear");
  for (int i = 0; i < SIZE_LINE_TABLE; i++) {
    for (int j = 0; j < SIZE_COLUMN_TABLE; j++) {
      printf("%c", table[i][j]);
    }
    printf("\n");
  }
}

void readMovePlayer(int player, Move_t *movePlayer) {
  Move_t testMove;

  while(TRUE) {
    printf("---------- PLAYER %d ----------\n\n", player);
    printf("Enter a coordinate (x, y) and a value\n> ");

    if (!readMove(&testMove)) {
      system("clear");
      printf("Invalid values!\nTry again!\n");
      continue;
    }
    if (!checkPoint(&testMove.movePoint)) {
      system("clear");
      printf("Invalid Point!\nTry again!\n");
      continue;
    }
    if (testMove.moveValue != 'o' && testMove.moveValue != 'x') {
      system("clear");
      printf("Invalid Move!\nTry again!\n");
      continue;
    }
    
    movePlayer->movePoint.x = testMove.movePoint.x;
    movePlayer->movePoint.y = testMove.movePoint.y;
    movePlayer->moveValue = testMove.moveValue;

    break;
  }
}

void setMovePlayer(char **table, Move_t *movePlayer) {
  int x, y;

  //adjusting point
  movePlayer->movePoint.x--;
  if (movePlayer->movePoint.y == 1) {
    movePlayer->movePoint.y--;
  } else if (movePlayer->movePoint.y == 3) {
    movePlayer->movePoint.y++;
  }

  if (!checkPoint(&movePlayer->movePoint)) {
    printf("Invalid Point!");
    exit(1);
  }

  x = movePlayer->movePoint.x;
  y = movePlayer->movePoint.y;

  table[x][y] = movePlayer->moveValue; 
}

void freeTable(char **table) {
  for (int i = 0; i < SIZE_LINE_TABLE; i++) {
    free(table[i]);
  }
  free(table);
}

int checkPoint(Point *point) {
  return !(point->x < 0 || point->x > 3 || point->y < 0 || point->y > 5);
}

int checkColumns(char **table) {
  // implent
} 

int checkLines(char **table) {
  for (int i = 0; i < SIZE_LINE_TABLE; i++) {
    if (table[i][0] == 'x' && table[i][2] == 'x' && table[i][4] == 'x') {
      return 1;
    } else if (table[i][0] == 'o' && table[i][2] == 'o' && table[i][4] == 'o') {
      return 2; 
    }
  }
  return 0;
}

char** createTable() {
  char **table = (char **) malloc(SIZE_LINE_TABLE * sizeof(char *));

  for (int i = 0; i < SIZE_LINE_TABLE; i++) {
    table[i] = (char *) malloc(SIZE_COLUMN_TABLE * sizeof(char));
  }

  // filling table
  for (int i = 0; i < SIZE_LINE_TABLE; i++) {
    for (int j = 0; j < SIZE_COLUMN_TABLE; j++) {
      if (j % 2 == 0) {
        table[i][j] = '-';
      } else {
        table[i][j] = '|';
      }
    }
  }

  return table;
}
