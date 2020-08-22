//programa que transforma a letra digitada em maiusculo, caso a letra seja minuscula,
//caso a letra seja maiuscula ou não seja letra, simplesmente retornamos sem alterar

//importação de bibliotecas
#include <stdio.h>

//função que verifica se o caractere é um dígito
char maiuscula(char caractere);

//função principal
int main(void)
{
    //declaração de variáveis
    char caractere, caractere_modificado;

    //lendo caractere
    printf("Digite um caractere\n> ");
    scanf("%c", &caractere);

    //aplicando alterações no caractere
    caractere_modificado = maiuscula(caractere);

    //mostrando caractere modificado
    printf("O caractere modificado e:  %c", caractere_modificado);
       
    return 0;
}

char maiuscula(char caractere)
{
    //caso o caractere seja uma letra minuscula
    if(caractere >= 'a' && caractere <= 'z')
        //caractere recebe a letra maiuscula correspondente
        caractere = caractere - 'a' + 'A';

    //retornando o caractere
    return caractere;
}
