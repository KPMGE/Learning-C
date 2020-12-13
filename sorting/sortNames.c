// Simple program to sort names in alfabetic order

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZENAME 80

void sortNamesAlfabeticOrder(char names[][MAXSIZENAME], int qtdNames);
void readNames(char names[][MAXSIZENAME], int qtdNames);
void displayNames(char names[][MAXSIZENAME], int qtdNames);

int main(void)
{
  int qtdNames;

  printf("How many names do you want to sort? ");
  scanf("%d", &qtdNames);

  char names[qtdNames][MAXSIZENAME];

  readNames(names, qtdNames);
  sortNamesAlfabeticOrder(names, qtdNames);
  displayNames(names, qtdNames);

  return 0;
}

void readNames(char names[][MAXSIZENAME], int qtdNames)
{
  int i;

  printf("Enter names:\n");
  for (i = 0; i < qtdNames; i++)
  {
    scanf("%s", names[i]);
  }
}

void sortNamesAlfabeticOrder(char names[][MAXSIZENAME], int qtdNames)
{
  int i, j;
  char aux[MAXSIZENAME];

  for (i = 0; i < qtdNames; i++)
  {
    for (j = i + 1; j < qtdNames; j++)
    {
      if (strcmp(names[i], names[j]) > 0)
      {
        strcpy(aux, names[i]);
        strcpy(names[i], names[j]);
        strcpy(names[j], aux);
      }
    }
  }
}

void displayNames(char names[][MAXSIZENAME], int qtdNames)
{
  int i;

  for (i = 0; i < qtdNames; i++)
  {
    printf("%s\n", names[i]);
  }
}
