#include <stdio.h>
#include <stdlib.h>
#include "./include/move.h"
#include "./include/game-functions.h"

int main(void) {
  system("clear");

  int winner = 0;
  Move_t *movePlayer = createMove();
  char **table = createTable();

  
  for (int i = 0; i < 9; i++) {
    readMovePlayer(1, movePlayer);
    printf("\n");
    setMovePlayer(table, movePlayer);
    displayTable(table);

    readMovePlayer(2, movePlayer);
    printf("\n");
    setMovePlayer(table, movePlayer);
    displayTable(table);
  }

  system("figlet game over");

  // releasing memory
  freeTable(table);
  freeMove(movePlayer);

  return 0;
}