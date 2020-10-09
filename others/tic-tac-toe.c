//Simple program, or actually a shit program, for tic-tac-toe game

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct point
{
  int x;
  int y;
};
typedef struct point Point;

void print_matrix(char matrix[][5], Point *p, char c);
void read_move(Point *p, char *c, int Player);
int check_row(char old[][5], int i);
int check_column(char old[][5], int j);
int check_diagonals(char old[][5]);
int end_game(char old[][5]);

int main(void)
{
  int i, j, cont = 0;
  Point p;
  char c, old[3][5];

  //creating matrix for game
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 5; j++)
    {
      if (j % 2 == 0)
        old[i][j] = '-';
      else
        old[i][j] = '|';
    }
  }

  printf("-------------------------------------TIC-TAC-TOE-----------------------------------------------\n");
  printf("Player 1 = 'x'\nPlayer 2 = 'o'\n");
  printf("Ready? Go!\n");

  while (TRUE)
  {
    printf("\nPlayer 1\n");
    read_move(&p, &c, 1);
    printf("\n");
    print_matrix(old, &p, c);
    printf("\nPlayer 2\n");
    read_move(&p, &c, 2);
    print_matrix(old, &p, c);

    cont++;

    if (end_game(old) == 1)
    {
      printf("Player 1 won!!");
      exit(1);
    }
    if (end_game(old) == 2)
    {
      printf("O Player 2 won!!");
      exit(1);
    }
    if (cont == 9)
    {
      printf("Old!!");
      return 0;
    }
  }

  printf("End Game!!");

  return 0;
}

void print_matrix(char old[][5], Point *p, char c)
{
  int i, j;

  old[p->x][p->y] = c;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 5; j++)
    {
      printf("%c ", old[i][j]);
    }
    printf("\n");
  }
}

void read_move(Point *p, char *c, int Player)
{
  while (TRUE)
  {
    printf("Type a point and a value\n> ");
    scanf("%d %d %c", &p->x, &p->y, c);

    if (Player == 1)
    {
      if ('x' != *c)
        printf("\nType the letter 'x' to play!!\n");
      else if (p->x > 3 || p->y > 4)
        printf("\nThere are no this point! Try again!!\n");
      else
        break;
    }
    if (Player == 2)
    {
      if ('o' != *c)
        printf("\nType the letter 'o' to play!!\n");
      else if (p->x > 3 || p->y > 4)
        printf("\nThere are no this point! Try again!!\n");
      else
        break;
    }
  }

  //adjusting point
  p->x -= 1;
  if (p->y == 1)
    p->y -= 1;
  if (p->y == 3)
    p->y += 1;
}

int check_row(char old[][5], int i)
{
  if ((old[i][0] == 'x' && old[i][2] == 'x' && old[i][4] == 'x'))
    return 1;
  else if ((old[i][0] == 'o' && old[i][2] == 'o' && old[i][4] == 'o'))
    return 2;
}

int check_column(char old[][5], int j)
{
  if ((old[0][j] == 'x' && old[1][j] == 'x' && old[2][j] == 'x'))
    return 1;
  else if ((old[0][j] == 'o' && old[1][j] == 'o' && old[2][j] == 'o'))
    return 2;
}

int check_diagonals(char old[][5])
{
  if ((old[0][0] == 'x' && old[1][2] == 'x' && old[2][4] == 'x') || (old[0][2] == 'x' && old[1][2] == 'x' && old[0][4] == 'x'))
    return 1;
  else if ((old[0][0] == 'o' && old[1][2] == 'o' && old[2][4] == 'o') || (old[0][2] == 'x' && old[1][2] == 'x' && old[0][4] == 'x'))
    return 2;
}

int end_game(char old[][5])
{
  int i, j;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 5; j++)
    {
      if ((check_row(old, i) == 1) || (check_column(old, j) == 1) || (check_diagonals(old) == 1))
        return 1;
      else if ((check_row(old, i) == 2) || (check_column(old, j) == 2) || (check_diagonals(old) == 2))
        return 2;
    }
  }
}
