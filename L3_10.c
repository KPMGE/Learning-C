/*
(BOCA:L3_10) 
Problema: O irmão de Ana sendo muito experto descobriu como ela
codificou os textos dela na L2_17, por conta disso, ela veio recorrer novamente a
você, pra que você faça melhorias pro programa pra que dessa vez ninguém
descubra o que há nos textos codificados.
Para melhorar seu código, o primeiro passo é modularizar.

a) A codificação agora deverá ser feita por uma função que recebe uma letra e a
n de codificação (inteiro) e retornará a letra codificada. A função deverá ter o
seguinte cabeçalho: char Codifica(char letra, int n);

b) De forma análoga, deverá ser feita uma função que decodifique uma letra,
recebendo como parâmetro a letra e um inteiro que represente a n de
codificação e retornar a letra Decodificada. A função deverá ter o seguinte
cabeçalho: char Decodifica (char letra, int n);
Depois das funções básicas serem feitas, Ana também gostaria que as letras
maiúsculas dessa vez também fossem cofidicadas, só que com a n 2 vezes maior
que a n normal, ou seja, se a chave é 2, a letra a vira c e a letra A vira E.

Para
diferenciar os caracteres recebidos, crie as funções:

a) int EhLetra (char c) que recebe um caractere e retorna verdadeiro se for letra e
falso caso contrário.

b) int EhLetraMaiuscula (char c) que recebe um caractere e retorna verdadeiro se ele
for letra maiúscula e falso caso contrário;

c) int EhLetraMinuscula (char c) que recebe um caractere e retorna verdadeiro se for
letra minúscula e falso caso contrário.
Atenção: Números e outros caracteres que por ventura apareçam no texto não
deverão ser codificados.

Entrada: dois números inteiros representando modo codificador ou Decodificador e a n
de codificação seguidos do texto que terminado por um ponto ‘.’.
Saída: o texto codificado ou Decodificado.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//função que  verifica se o caractere é uma letra
int EhLetra (char c);

//função que verifica se o caractere é uma letra maiúscula
int EhLetraMaiuscula(char c);

//função que verifica se o caractere é uma letra minúscula
int EhLetraMinuscula(char c);

//funçao que codifica a letra dada
char Codifica(char letra, int n);

//funçao  que Decodifica a letra dada
char Decodifica (char letra, int n);

//funçao principal
int main(void)
{
    //declaração de variaveis
    int modo, n, i;
    char texto[50];

    //lendo o modo de operação e n
    scanf("%d %d", &modo, &n);

    //escolhendo o modo de trabalho
    switch(modo)
    {
        case 1:
            //leitura dos dados
            scanf(" %50[^.]", texto);

            for(i = 0; i < strlen(texto); i++)
                //codificamos a letra no loop que estamos
                texto[i] = Codifica(texto[i], n);

            //mostrando o texto final
            printf("%s.", texto);    
            
            //apos a execuçao saimos do switch
            break;

        case 2:
            //leitura dos dados
            scanf(" %50[^.]", texto);

            for(i = 0; i < strlen(texto); i++)
                //codificamos a letra no loop que estamos
                texto[i] = Decodifica(texto[i], n);

            //mostrando o texto final
            printf("%s.", texto);    
            
            //apos a execuçao saimos do switch
            break;

        //caso nenhuma das opções acima seja escolhida
        default:
            printf("Operacao invalida.");
    }
    
    return 0;
}

//função que  verifica se o caractere é uma letra
int EhLetra (char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0;
}

//função que verifica se o caractere é uma letra maiúscula
int EhLetraMaiuscula(char c)
{
    if(EhLetra(c))
    {
        return (c >= 'A' && c <= 'Z') ? 1 : 0;
    }
}

//função que verifica se o caractere é uma letra minúscula
int EhLetraMinuscula(char c)
{
    if(EhLetra(c))
    {
        return (c >= 'a' && c <= 'z') ? 1 : 0;
    }
}

//funçao que codifica a letra dada
char Codifica(char letra, int n)
{
    //caso o caractere seja uma letra maiuscula
    if(EhLetraMaiuscula(letra))
    {
        n *= 2;
        letra += n;
    }
    //caso o caractere seja uma letra minuscula
    if(EhLetraMinuscula(letra))
        //letra codificada aplicando a n
        letra += n;

    //retornando letra
    return letra;
}

//funçao  que Decodifica a letra dada
char Decodifica (char letra, int n)
{
    //caso o caractere seja uma letra minuscula
    if(EhLetraMinuscula(letra))
        //letra Decodificada retirando a n
        letra -= n;
    if(EhLetraMaiuscula(letra))
    {
        n /= 2;
        letra -= n;
    }

    //retornando leltra
    return letra;
}
