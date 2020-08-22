/*
(BOCA:L2_17) 
Problema: Ana queria codificar seus textos para que mais ninguém lesse, e decodificá-los para quando ela quisesse ler. Para isso, faça um programa que contenha essas duas opções. Serão dados dois números inteiros e um texto terminado em ponto. O primeiro número é referente a opção (1 para codificar ou 2 para decodificar) que a pessoa quer e o segundo número será um número n referente ao código da codificação, ou seja, dada a opção 1, codifique o texto “somando” as letras minúsculas do texto a esse valor n para que o texto fique codificado. Exemplo: se n = 2, a letra a vira c, a letra n vira p, a letra z vira b, e assim sucessivamente. Dada a opção 2 com n = 1, o programa deve decodificar o texto revertendo o texto para o original, ou seja, a letra c vira b, a letra a vira z, e assim sucessivamente. Se for dada uma opção diferente das opções acima o programa deverá imprimir: “Operacao invalida.”. 

Atenção: Não deverão ser codificadas as letras maiúsculas. Números e outros caracteres que por ventura apareçam no texto não deverão ser codificados. Serão testados no BOCA outras entradas além das apresentadas nos exemplos.

• Entrada: dois números inteiros representando o modo codificador ou decodificador e a chave de codificação seguido do texto que será sempre terminado com um ponto, i.e., “.”.

• Saída: o texto codificado ou decodificado.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//funçao que verifica se o caractere é uma letra minuscula
int verificaLetraMinuscula(char caractere);

//funçao que codifica a letra dada
char codifica(char letra, int chave);

//funçao  que decodifica a letra dada
char decodifica(char letra, int chave);

//funçao principal
int main(void)
{
    //declaração de variaveis
    int modo, i, chave;
    char texto[101];

    //lendo o modo de operação e chave
    scanf("%d %d", &modo, &chave);

    //escolhendo o modo de trabalho
    switch(modo)
    {
        //caso o modo 1 seja escolhido
        case 1:
           //leitura do texto até encontrar um ponto final
            scanf("%100[^.]", texto);

            //percorrendo o texto
            for(i = 0; i < strlen(texto); i++)
                //codificamos a letra no loop que estamos
                texto[i] = codifica(texto[i], chave);

            //mostrando o texto final
            printf("%s.", texto);    
            
            //apos a execuçao saimos do switch
            break;

        case 2:
           //leitura do texto até encontrar um ponto final
            scanf("%100[^.]", texto);

            //percorrendo o texto
            for(i = 0; i < strlen(texto); i++)
                //codificamos a letra no loop que estamos
                texto[i] = decodifica(texto[i], chave);

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

int verificaLetraMinuscula(char caractere)
{
    return (caractere >= 'a' && caractere <= 'z') ? 1 : 0;
}

char codifica(char letra, int chave)
{
    //caso o caractere seja uma letra minuscula
    if(verificaLetraMinuscula(letra))
        //letra codificada aplicando a chave
        letra += chave;

    return letra;
}

char decodifica(char letra, int chave)
{
    //caso o caractere seja uma letra minuscula
    if(verificaLetraMinuscula(letra))
        //letra decodificada retirando a chave
        letra -= chave;

    return letra;
}
