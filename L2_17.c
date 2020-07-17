/*
(BOCA:L2_17) 
Problema: Ana queria codificar seus textos para que mais ninguém lesse, e decodificá-los para quando ela quisesse ler. Para isso, faça um programa que contenha essas duas opções. Serão dados dois números inteiros e um texto terminado em ponto. O primeiro número é referente a opção (1 para codificar ou 2 para decodificar) que a pessoa quer e o segundo número será um número n referente ao código da codificação, ou seja, dada a opção 1, codifique o texto “somando” as letras minúsculas do texto a esse valor n para que o texto fique codificado. Exemplo: se n = 2, a letra a vira c, a letra n vira p, a letra z vira b, e assim sucessivamente. Dada a opção 2 com n = 1, o programa deve decodificar o texto revertendo o texto para o original, ou seja, a letra c vira b, a letra a vira z, e assim sucessivamente. Se for dada uma opção diferente das opções acima o programa deverá imprimir: “Operacao invalida.”. 

Atenção: Não deverão ser codificadas as letras maiúsculas. Números e outros caracteres que por ventura apareçam no texto não deverão ser codificados. Serão testados no BOCA outras entradas além das apresentadas nos exemplos.

• Entrada: dois números inteiros representando o modo codificador ou decodificador e a chave de codificação seguido do texto que será sempre terminado com um ponto, i.e., “.”.

• Saída: o texto codificado ou decodificado.
*/

//importação de bibliotecas
#include <stdio.h>


//funçao que verifica se chegamos ao final do texto
int verificaFinalTexto(char caractere)
{
    //caso cheguemos ao final, retornamos 0(falso), parando o loop
    if(caractere == '.')
    {
        return 0;
    }
    //caso contrario, retornamos 1(verdadeiro), mantendo o loop
    else
    {
        return 1;
    }  
}


//funçao que verifica se o caractere é uma letra minuscula
int verificaLetraMinuscula(char caractere)
{
    if(caractere >=97 && caractere<= 122)
    {
        return 1;
    }else
    {
        return 0;
    }
}


//funçao que codifica a letra dada
char codifica(char letra, int chave)
{
    //caso o caractere seja uma letra minuscula
    if(verificaLetraMinuscula(letra))
    {
        //letra codificada aplicando a chave
        letra += chave;

        return letra;
    }else
    {
        return letra;
    }
}


//funçao  que decodifica a letra dada
char decodifica(char letra, int chave)
{
    //caso o caractere seja uma letra minuscula
    if(verificaLetraMinuscula(letra))
    {
        //letra decodificada retirando a chave
        letra -= chave;

        return letra;
    }else
    {
        return letra;
    }
}


//funçao principal
int main()
{
    //declaração de variaveis
    int modo, chave, i=-1;
    char texto[50];

    //lendo o modo de operação e chave
    scanf("%d %d", &modo, &chave);

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
                texto[i] = codifica(texto[i], chave);
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

                //texto na posição de i recebe o retorno da função decodifica
                texto[i] = decodifica(texto[i], chave);
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