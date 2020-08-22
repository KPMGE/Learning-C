//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//função principal
int main(void)
{
    char string[50], string2[50], string_concatenada[100], string_copia[50];
    int tamanho;

    //lendo string
    printf("Digite uma string de e tecle Enter para confirmar\n: ");
    scanf(" %50[^\n]", string);


    //com a função 'strcpy()', copiamos os caracteres de uma string para outra, supondo sempre que haja espaço suficiente para tanto
    printf("\nCopiando string...\n");

    //copiando de string para string_copia
    strcpy(string_copia, string);

    printf("Resultado: %s\n\n", string_copia);


    //com a função 'strlen()', obtemos o tamanho da string, excluindo o caractere nulo '\0'
    tamanho = strlen(string);
    printf("A string tem o tamanho de: %d\n\n", tamanho);

    
    //com a função 'strcat()', concatenamos strings, ou seja, a primeira se junta com o inicio da segunda
    printf("Digite uma string para concatenar: ");
    scanf(" %50[^\n]", string_concatenada);

    //concatenando
    strcat(string_concatenada, string);
    
    printf("Resultado: %s\n\n", string_concatenada);


    //com a função 'strcmp()', temos 3 resultados de retorno possiveis:
    //retono (menor que 0), se a primeira string preceder a primeira 
    //retorno (maior que 0), se a segunda string preceder a primeira
    //retorno (0), se as duas strings forem exatamente iguais

    //lendo string1
    printf("Digite uma string e tecle Enter para confirmar: ");
    scanf(" %50[^\n]", string);

    //lendo string2
    printf("Digite outra string e tecle Enter para confirmar: ");
    scanf(" %50[^\n]", string2);

    //pulando uma linha
    printf("\n");

    if(strcmp(string, string2) > 0)
        printf("A segunda string precede a primeira");
    
    if(strcmp(string, string2) < 0)
        printf("A primeira string precede a segunda");

    if(strcmp(string, string2) == 0)
        printf("As duas strings sao iguais");

    return 0;
}
