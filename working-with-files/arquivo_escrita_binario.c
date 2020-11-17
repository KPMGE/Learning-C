/**
Escrita em um arquivo binario
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("exemplo.bin","w");
    

    float x = 5.7;
    

    if (fp == NULL){
      printf("Erro na abertura do arquivo\n");
      exit(1);
    }

    //grava o texto inteiro no arquivo
    fwrite("Hello World\n", sizeof(char), 12, fp);

    //grava apenas os 5 primeiros caracteres do texto
    fwrite("Hello World", sizeof(char), 5, fp);

    //grava o valor de x
    fwrite(&x, sizeof(float), 1, fp);

    fclose(fp);
    return 0;
}
