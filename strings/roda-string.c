//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//função que 'roda' a string
void roda_string(char* str);

//função principal
int main(void)
{
    //vetor para a string
    char str[101];

    //lendo string
    printf("Digite uma string: ");
    scanf(" %100[^\n]", str);
    
    //usando a função para modificar a string
    roda_string(str);

    //mostrando resultados
    printf("Resultado: %s", str);

    return 0;
}

void roda_string(char* str)
{
    int i, n = strlen(str) - 1;

    for(i = 1; i < n -1; i++)
    {
        str[i] = str[i + 1];
    }

    str[0] = str[strlen(str) - 1];
}
