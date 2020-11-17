/**
Exemplo de uso de fgetc, fputc, fscanf e fprintf
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
  char ch;
  float b, h;
  FILE *arq_in, *arq_out;

  arq_in = fopen("retangulo.txt", "r");
  if(arq_in == NULL){
      printf("Erro, nao foi possivel abrir o arquivo\n");
      exit(1);
  }

  arq_out = fopen("area_retangulo.txt", "w");
  if(arq_out == NULL){
      printf("Erro, nao foi possivel abrir o arquivo\n");
      exit(1);
  }

  while( (ch=fgetc(arq_in))!= '\n' )
    fputc (ch, stdout);

  putchar('\n');

  fscanf(arq_in,"%f%f", &b, &h);
    
  printf("%.2f %.2f\n", b, h);

  fprintf(arq_out,"Area do retangulo: %.2f\n", b*h);

  fclose(arq_in);
  fclose(arq_out);

  return 0;
}
