/**
Abertura e fechamento de um arquivo
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("exemplo.txt","r");
    if (fp == NULL){
      printf("Erro na abertura do arquivo\n");
      exit(1);
    }

    fclose(fp);
    return 0;
}
