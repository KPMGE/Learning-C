/**
Leitura em um arquivo
Exemplo do FEOF
*/
#include<stdio.h>
#include<stdlib.h>


int main()
{
	FILE *fp;
	int c;

	fp = fopen("exemplo1.txt","r");
	if (fp == NULL){
		printf("Erro na abertura do arquivo\n");
		exit(1);
	}
	//modo errado: 
	/*
	while (!feof(fp)) {
		fscanf(fp, "%d", &c);
		printf("%d\n",c);
	}*/

	//modo certo:
	while (!feof(fp)) {
		fscanf(fp, "%d", &c);
		if (feof(fp))
			break;
		printf("%d\n",c);
	}

	fclose(fp);
	
	return 0;
}
