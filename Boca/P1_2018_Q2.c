// Exercise: P1_2018_Q2
// Author: Kevin Carvalho de jesus

#include <stdio.h>
#include <stdlib.h>

int qtdNotes(int value);

int main(void)
{
  int change1, change2;

  scanf("%d %d", &change1, &change2);

  if(qtdNotes(change1) == qtdNotes(change2))
    printf("Iguais!");
  else if (qtdNotes(change1) > qtdNotes(change2))
    printf("QTD troco 1 eh maior!");
  else 
    printf("QTD troco 2 eh maior!");

  return 0;
}

int qtdNotes(int value)
{
  int qtdNotesFive, qtdNotesOne;
  qtdNotesFive = value / 5;
  qtdNotesOne = value - (qtdNotesFive * 5);
  return qtdNotesFive + qtdNotesOne;
}