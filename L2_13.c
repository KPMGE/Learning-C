/*
(BOCA:L2_13)
Problema: Faça um programa para substituir letras minúsculas de uma frase por letras maiúsculas. O programa deverá ler caracteres da entrada padrão (um por vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

OBS: “YES - Presentation diferences” não é uma resposta válida para essa questão.

• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Saída: a sequência de caracteres modificada.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//funçao que retorna a propria letra se já maiusculo, ou caractere se não a transforma em maiuscula
char transformaMaiusculo(char letra);

//funçao principal
int main(void)
{
    //declaraçao de variaveis
    char frase[50];
    int i;

    //leitura de dados até encontrar um caractere !, . ou ?
    scanf(" %[^.?!]", frase);

    //percorrendo frase
    for(i = 0; i < strlen(frase); i++)
        //transformamos a letra corresp{ondente ao indice q estamos
        frase[i] = transformaMaiusculo(frase[i]);

    //mostrando a frase na tela
    printf("%s", frase);

    return 0;
}

//funçao que retorna a propria letra se já maiusculo, ou caractere se não a transforma em maiuscula
char transformaMaiusculo(char letra)
{
    //caso a letra minuscula 
    if(letra >= 'a' && letra <= 'z')
        letra = letra - 'a' + 'A';

    //retornando letra
    return letra; 
}
