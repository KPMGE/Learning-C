//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//função que substitui as ocorrências de letras maiusculas por minusculas
void minusculo(char* str);

//função principal
int main(void)
{
    //vetor para a string
    char str[101];

    //lendo string
    printf("Digite uma frase: ");
    scanf(" %100[^\n]", str);

    //modificando string com a função
    minusculo(str);

    //mostrando resultados
    printf("Frase em micusculo: %s", str);

    return 0;
}

void minusculo(char* str)
{
    int i;

    //percorrendo string
    for(i = 0; i < strlen(str); i++)
        //caso a letra seja maiuscula
        if(str[i] >= 'A' && str[i] <= 'Z')
            //transformando a letra em minuscula
            str[i] = str[i] - 'A' + 'a';
}
