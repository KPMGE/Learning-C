#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Definição de estruturas

typedef struct ponto{
	float x;
	float y;
}tponto;

//Declaração das operacoes com pontos

tponto criaponto (void);
tponto somapontos (tponto, tponto);
double distancia(tponto, tponto);
void imprimeponto(tponto);
void imprimepontoArq(tponto, FILE*);

int main(){
	
	tponto p;
	int semente, i;
	
  FILE* fp;

  fp = fopen("exemplo_pontos.txt","w");
    if (fp == NULL){
      printf("Erro na abertura do arquivo\n");
      exit(1);
    }

  semente = 1;//time(NULL);
	srand(semente);

  for (i=0; i<10; i++){
    p = criaponto();
    imprimepontoArq(p, fp);
  }	
  
  fclose(fp);

}

tponto criaponto (void)
{
	tponto temp;

	
	temp.x = (rand()/(float) RAND_MAX)*100;
	temp.y = (rand()/(float) RAND_MAX)*100;

	return temp;
}

tponto somapontos (tponto p1, tponto p2)
{
	tponto s;

	s.x = p1.x + p2.x;
	s.y = p1.y + p2.y;

	return s;
}

double distancia(tponto p1, tponto p2)
{
	return sqrt(pow((p2.x - p1.x),2) + pow((p2.y-p1.y),2));
}

void imprimeponto(tponto p){

  printf("(%.2f, %.2f)", p.x, p.y);
}

void imprimepontoArq(tponto p, FILE* q){
  fprintf(q,"%.2f %.2f\n", p.x, p.y);
}

