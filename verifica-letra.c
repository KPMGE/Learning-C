//programa que verifica se o caractere digitado é uma letra

//importação de bibliotecas
#include <stdio.h>

//função que verifica se o caractere é uma letra
int verifica_letra(char caractere);

//função principal
int main(void)
{
    char caractere;

    //lendo caractere
    printf("Digite um caractere\n> ");
    scanf("%c", &caractere);

    //verificando se letra e mostrando mensagem
    if(verifica_letra(caractere))
        printf("O caractere e uma letra");
    else
        printf("O caractere nao e uma letra");

    return 0;
}

int verifica_letra(char caractere)
{
    return ((caractere >= 'a' && caractere <= 'z') || (caractere >= 'A' && caractere <= 'Z')) ? 1 : 0;
}
