#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

typedef struct
{
  float x;
  float y;
  int s;
} tPosicao;

typedef struct
{
  int id;
  tPosicao v[4];
} tRobo;

typedef struct
{
  int id;
  float distanciaTotal;
  int qtdResgatados;
} tDados;

void preencheRobos(tRobo r[], int n);
float distanciaTotal(tPosicao *p, int np);
void preencheDados(tRobo *r, tDados *d, int n);
int totalSobreviventes(tPosicao *p, int np);
void imprime_Resultados(tDados *robos, int n);
void ordenaRobos(tDados robos[], int n);
int roboQuePercorreuAMaiorDistancia(tDados robos[], int n);

int main(void)
{
  int n;
  tRobo robos[25];
  tDados dadosRobos[25];

  scanf("%d", &n);

  preencheRobos(robos, n);
  preencheDados(robos, dadosRobos, n);
  ordenaRobos(dadosRobos, n);
  imprime_Resultados(dadosRobos, n);

  return 0;
}

void preencheRobos(tRobo r[], int n)
{
  int i, j;
  srand(1);

  for (i = 0; i < n; i++)
  {
    r[i].id = i;

    for (j = 0; j < 4; j++)
    {
      r[i].v[j].s = (rand() / (float)RAND_MAX) * 20;
      r[i].v[j].x = (rand() / (float)RAND_MAX) * 100.0;
      r[i].v[j].y = (rand() / (float)RAND_MAX) * 100.0;
    }
  }
}

float distanciaTotal(tPosicao *p, int np)
{
  int i;
  float total = 0;
  np = 4;
  for (i = 0; i < 4; i++)
  {
    total += sqrt(pow(p[i].x, 2) + pow(p[i].y, 2));
  }
  return total;
}

void preencheDados(tRobo *r, tDados *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    d[i].id = r[i].id;
    d[i].distanciaTotal = distanciaTotal(r[i].v, n);
    d[i].qtdResgatados = totalSobreviventes(r[i].v, n);
  }
}

int totalSobreviventes(tPosicao *p, int np)
{
  int i, total = 0;
  for (i = 0; i < 4; i++)
  {
    total += p[i].s;
  }
  return total;
}

void ordenaRobos(tDados robos[], int n)
{
  int i, j, aux, aux2;

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n - 1; j++)
    {
      if (robos[j].qtdResgatados < robos[j + 1].qtdResgatados)
      {
        aux = robos[j].qtdResgatados;
        aux2 = robos[j].id;
        robos[j].qtdResgatados = robos[j + 1].qtdResgatados;
        robos[j].id = robos[j + 1].id;
        robos[j + 1].qtdResgatados = aux;
        robos[j + 1].id = aux2;
      }
    }
  }
}

int roboQuePercorreuAMaiorDistancia(tDados robos[], int n)
{
  int i, maior = robos[0].id;
  for (i = 1; i < n; i++)
  {
    if (robos[i].distanciaTotal > maior)
    {
      maior = robos[i].id;
    }
  }
  return maior;
}

void imprime_Resultados(tDados *robos, int n)
{
  int i;

  printf("INFORMACOES PROCESSADAS:\n\n");
  printf("Robo que percorreu maior distancia no terreno acidentado: %d\n\n", roboQuePercorreuAMaiorDistancia(robos, n));
  printf("-----------------------------------\n\n");
  printf("Lista de robos que resgataram sobreviventes no terreno acidentado, ordenados pelo maior numero de resgatados:\n\n");

  for (i = 0; i < n; i++)
  {
    printf("%d: %d %.3f\n", robos[i].id, robos[i].qtdResgatados, robos[i].distanciaTotal);
  }

  printf("\n-----------------------------------");
}