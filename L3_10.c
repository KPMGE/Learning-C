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


Entrada: dois números inteiros representando modo codificador ou Decodificador e a n
de codificação seguidos do texto que terminado por um ponto ‘.’.
Saída: o texto codificado ou Decodificado.
*/

//importação de bibliotecas
#include <stdio.h>

//funçao que verifica se chegamos ao final do texto
int verificaFinalTexto(char caractere);

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
int main()
{
    //declaração de variaveis
    int modo, n, i=-1;
    char texto[50];

    //lendo o modo de operação e n
    scanf("%d %d", &modo, &n);

    //escolhendo o modo de trabalho
    switch(modo)
    {
        //caso o modo 1 seja escolhido
        case 1:
            //loop enquanto não chegarmos ao ponto final
            do
            {
                //incremento na variável i
                i++;

                //leitura dos dados
                scanf("%c", &texto[i]);

                //codificamos a letra no loop que estamos
                texto[i] = Codifica(texto[i], n);
            }while(verificaFinalTexto(texto[i]));

            //mostrando o texto final
            printf("%s", texto);    
            
            //apos a execuçao saimos do switch
            break;

        case 2:
            //loop enquanto não chegarmos ao ponto final
            do
            {
                //incremento em i
                i++;

                //leitura dos dados
                scanf("%c", &texto[i]);

                //texto na posição de i recebe o retorno da função Decodifica
                texto[i] = Decodifica(texto[i], n);
            }while(verificaFinalTexto(texto[i]));
            
            //mostrando o texto final
            printf("%s", texto);

            //apos a execuçao saimos do switch
            break;

        //caso nenhuma das opções acima seja escolhida
        default:
            printf("Operacao invalida.");
    }
    
    return 0;
}

//funçao que verifica se chegamos ao final do texto
int verificaFinalTexto(char caractere)
{
    //caso cheguemos ao final, retornamos 0(falso), parando o loop
    if(caractere== '.')
        return 0;
    //caso contrario, retornamos 1(verdadeiro), mantendo o loop
    else
        return 1;
}

//função que  verifica se o caractere é uma letra
int EhLetra (char c)
{
    if(c > 64 && c < 91 || c > 96 && c < 123)
        return 1;
    else
        return 0;
}

//função que verifica se o caractere é uma letra maiúscula
int EhLetraMaiuscula(char c)
{
    if(EhLetra(c))
    {
        if(c >= 65 && c <= 90)
            return 1;
        else
            return 0;
    }
}

//função que verifica se o caractere é uma letra minúscula
int EhLetraMinuscula(char c)
{
    if(EhLetra(c))
    {
        if(c >= 95 && c <= 122)
            return 1;
        else
            return 0;
    }
}

//funçao que codifica a letra dada
char Codifica(char letra, int n)
{
    if(EhLetraMaiuscula(letra))
    {
        n *= 2;
        letra += n;
        return letra;
    }
    //caso o caractere seja uma letra minuscula
    if(EhLetraMinuscula(letra))
    {
        //letra codificada aplicando a n
        letra += n;
        return letra;
    }
    else
        return letra;
}

//funçao  que Decodifica a letra dada
char Decodifica (char letra, int n)
{
    //caso o caractere seja uma letra minuscula
    if(EhLetraMinuscula(letra))
    {
        //letra Decodificada retirando a n
        letra -= n;
        return letra;
    }
    if(EhLetraMaiuscula(letra))
    {
        n /= 2;
        letra -= n;
        return letra;
    }
    else
        return letra;
}
