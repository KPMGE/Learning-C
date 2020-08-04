//programa que verifica se o caractere digitado é um digito numérico

//importação de bibliotecas
#include <stdio.h>

//função que verifica se o caractere é um dígito
int verifica_digito(char caractere);

//função principal
int main(void)
{
    char caractere;

    //lendo caractere
    printf("Digite um caractere\n> ");
    scanf("%c", &caractere);

    //verificando se digito e mostrando mensagem
    if(verifica_digito(caractere))
        printf("O caractere e um digito");
    else
        printf("O caractere nao e um digito");

    return 0;
}

int verifica_digito(char caractere)
{
    return (caractere > '0' && caractere < '9') ? 1 : 0;
}
