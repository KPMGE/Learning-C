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

tponto leponto (FILE*);


int main(){
	
	FILE* fp;
	tponto p;
	int i;
	float vetor_coordenadasx[10];
	float vetor_coordenadasy[10];

	fp = fopen("lista_pontos.txt","r");
    	if (fp == NULL){
      		printf("Erro na abertura do arquivo\n");
      		exit(1);
    	}

  	for (i=0; i<10; i++){
    		p = leponto(fp);    
		vetor_coordenadasx[i] = p.x;
		vetor_coordenadasy[i] = p.y;
  	}	
  
	printf("Coordenadas em x:");
	for (i=0; i<10; i++){
    		printf("%.2f ", vetor_coordenadasx[i]);
  	}

	printf("\nCoordenadas em y:");
	for (i=0; i<10; i++){
    		printf("%.2f ", vetor_coordenadasy[i]);
  	}
	printf("\n");

  	fclose(fp);

}

tponto leponto (FILE* fp)
{
	tponto temp;

	
	fscanf(fp,"%f%f",&temp.x, &temp.y);

	return temp;
}


