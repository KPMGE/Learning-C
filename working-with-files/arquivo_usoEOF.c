/**
Leitura em um arquivo
Exemplo do uso de EOF
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	char c;
	int ncaracteres = 0;

	fp = fopen("exemplo.txt","r");
	if (fp == NULL){
		printf("Erro na abertura do arquivo\n");
		exit(1);
	}

	//Imprime na telacaractere a caractere

	
	while ((c = fgetc(fp)) != EOF){
		printf("%c",c);
		ncaracteres++;
	}
	printf("Total de caracteres: %d\n", ncaracteres);
	fclose(fp);
	
	return 0;
}
