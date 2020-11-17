/**
Leitura e movimentação (fread e fseek) em um arquivo binario
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("exemplo.bin","r");
    
    char c;
    float x;
   

    if (fp == NULL){
      printf("Erro na abertura do arquivo\n");
      exit(1);
    }

    //Lê o valor da primeira letra do arquivo:
    fread(&c, sizeof(char), 1, fp);

    printf("c = %c\n", c);
   
    //Move a posição para o início da codificação do valor float
    fseek(fp, 17*sizeof(char), SEEK_SET);

    //Lê o valor float e atribui à variável x
    fread(&x, sizeof(float), 1, fp);

    printf("%.2f\n", x);

    fclose(fp);
    return 0;
}
