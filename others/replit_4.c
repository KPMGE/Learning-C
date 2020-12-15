// Exercise: fourth replit
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int qtdEdsger;
  int qtdCarol;
  int qtdTuring;
  int qtdTim;
  int qtdLinus;
  int qtdAda;
} Election;

double calculatePercentage(int total, int number);
int isItTie(int qtd1, int qtd2, int qtd3);
int idWinnerMinister(int qtd1, int qtd2, int qtd3);
int idWinnerPresident(int qtd1, int qtd2, int qtd3);
void displayPresident(Election currentElection, int validVotes);
void displayMinister(Election currentElection, int validVotes);
void displayResultElection(Election currentElection, int whiteNullPresident, int whiteNullMinister, float percentage, int qtdValidVotes, int boolVar);

int main(void)
{
  int id, presidentNumber, ministerNumber, qtdPeople, cont = 0, whiteNullMinister = 0, whiteNullPresident = 0, validVote = 0;
  int currentId;
  Election currentElection;

  currentElection.qtdEdsger = 0;
  currentElection.qtdCarol = 0;
  currentElection.qtdTuring = 0;
  currentElection.qtdTim = 0;
  currentElection.qtdLinus = 0;
  currentElection.qtdAda = 0;

  scanf("%d", &qtdPeople);

  while (scanf("%d %d %d", &id, &presidentNumber, &ministerNumber) == 3)
  {
    cont++;
    if (cont == 1)
      currentId = id;
    if (cont != 1 && ((cont > qtdPeople) || (currentId == id)))
    {
      printf("ELEICAO ANULADA");
      exit(0);
    }
    if (presidentNumber == 0 && ministerNumber == 0)
    {
      validVote++;
    }
    if ((presidentNumber != 10 && presidentNumber != 42 && presidentNumber != 26))
      whiteNullPresident++;
    if ((ministerNumber != 36 && ministerNumber != 64 && ministerNumber != 18))
      whiteNullMinister++;
    else
    {
      validVote++;
      if (presidentNumber == 10)
        currentElection.qtdEdsger++;
      if (presidentNumber == 42)
        currentElection.qtdCarol++;
      if (presidentNumber == 26)
        currentElection.qtdTuring++;
      if (ministerNumber == 36)
        currentElection.qtdTim++;
      if (ministerNumber == 64)
        currentElection.qtdLinus++;
      if (ministerNumber == 18)
        currentElection.qtdAda++;
    }
  }

  displayResultElection(currentElection, whiteNullPresident, whiteNullMinister, calculatePercentage(qtdPeople, validVote), validVote, (validVote <= (whiteNullMinister + whiteNullPresident)));

  return 0;
}

double calculatePercentage(int total, int number)
{
  return (number * 100.0000) / total;
}

int isItTie(int qtd1, int qtd2, int qtd3)
{
  if (qtd1 == 0 || qtd2 == 0 || qtd3 == 0)
    return 0;
  else if (qtd1 == qtd2 || qtd1 == qtd3)
    return 1;
  else if (qtd2 == qtd3)
    return 1;
  else
    return 0;
}

int idWinnerMinister(int qtd1, int qtd2, int qtd3)
{
  if (qtd1 > qtd2 && qtd1 > qtd3)
    return 36;
  else if (qtd2 > qtd3)
    return 64;
  else
    return 18;
}

int idWinnerPresident(int qtd1, int qtd2, int qtd3)
{
  if (qtd1 > qtd2 && qtd1 > qtd3)
    return 10;
  else if (qtd2 > qtd3)
    return 42;
  else
    return 26;
}

void displayPresident(Election currentElection, int totalVotes)
{
  switch (idWinnerPresident(currentElection.qtdEdsger, currentElection.qtdCarol, currentElection.qtdTuring))
  {
  case 10:
    printf("Edsger Dijkstra (Partido do Melhor Caminho (PMC)), %d, %.2f%%\n", currentElection.qtdEdsger, calculatePercentage(totalVotes, currentElection.qtdEdsger));
    break;

  case 42:
    printf("Alan Turing (Partido dos Avanço Intelectual (PAI), %d, %.2f%%\n)", currentElection.qtdTuring, calculatePercentage(totalVotes, currentElection.qtdTuring));
    break;

  case 26:
    printf("Carol Shaw (Gamers Unidos (GU)), %d, %.2f%%\n", currentElection.qtdCarol, calculatePercentage(totalVotes, currentElection.qtdCarol));
    break;
  }
}

void displayMinister(Election currentElection, int totalVotes)
{
  switch (idWinnerMinister(currentElection.qtdTim, currentElection.qtdLinus, currentElection.qtdAda))
  {
  case 36:
    printf("Tim Berners-Lee (World Wide Web (WWW)), %d, %.2f%%\n", currentElection.qtdTim, calculatePercentage(totalVotes, currentElection.qtdTim));
    break;

  case 64:
    printf("Linus Torvalds (Linux (Linux)), %d, %.2f%%\n", currentElection.qtdLinus, calculatePercentage(totalVotes, currentElection.qtdLinus));
    break;

  case 18:
    printf("Ada Lovelace (Mulheres Programadoras Unidas (MPU)), %d, %.2lf%%\n", currentElection.qtdAda, calculatePercentage(totalVotes, currentElection.qtdAda));
    break;
  }
}

void displayResultElection(Election currentElection, int whiteNullPresident, int whiteNullMinister, float percentage, int qtdValidVotes, int boolVar)
{
  if (isItTie(currentElection.qtdEdsger, currentElection.qtdCarol, currentElection.qtdTuring))
  {
    printf("FIM DA ELEICAO\n");
    printf("- PRESIDENTE ELEITO: EMPATE\n");
    printf("- PRIMEIRO MINISTRO ELEITO: ");
    displayMinister(currentElection, qtdValidVotes);
    printf("- COMPARECIMENTO: %.2f%%\n", percentage);
    printf("- NULOS E BRANCOS: %d, %d", whiteNullPresident, whiteNullMinister);
  }
  else if (boolVar)
  {
    printf("FIM DA ELEICAO\n");
    printf("- PRESIDENTE ELEITO: SEM DECISAO\n");
    printf("- PRIMEIRO MINISTRO ELEITO: ");
    displayMinister(currentElection, qtdValidVotes);
    printf("- COMPARECIMENTO: %.2f%%\n", percentage);
    printf("- NULOS E BRANCOS: %d, %d", whiteNullPresident, whiteNullMinister);
  }
  else
  {
    printf("FIM DA ELEICAO\n");
    printf("- PRESIDENTE ELEITO: ");
    displayPresident(currentElection, qtdValidVotes);
    printf("- PRIMEIRO MINISTRO ELEITO: ");
    displayMinister(currentElection, qtdValidVotes);
    printf("- COMPARECIMENTO: %.2f%%\n", percentage);
    printf("- NULOS E BRANCOS: %d, %d", whiteNullPresident, whiteNullMinister);
  }
}
