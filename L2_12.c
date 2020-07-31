/*
(BOCA:L2_12) 
Problema: Faça um programa para substituir caracteres espaço ‘ ‘ por caracteres underline ‘_’ de uma frase. O programa deverá ler caracteres da entrada padrão (um por vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Saída: “RESP:” seguido da sequência de caracteres modificada.
*/


//importação de bibliotecas
#include <stdio.h>


//funçao que verifica o caractere final
int verificaFinalCaractere(char caractere)
{
    //caso o caractere seja . ! ou ? retornamos 0, caso contrario, 1
    if(caractere == '.' || caractere == '!' || caractere == '?')
    {
        return 0;
    }else
    {
        return 1;
    }   
}


//funçao que verifica se o caractere é um espaço, se sim, troca o mesmo por underline _
char trocaEspaco(char caractere)
{
    //caso o caractere seja um espaço em branco
    if(caractere == ' ')
    {
        //caractere recebe underline
        caractere = '_';
    }

    //retornando caractere
    return caractere;
}


//funçao principal
int main()
{
    //vetor para a frase
    char frase[50];

    //como incrementamos i logo no começo do loop, usamos seu valor como -1, assim ao fazer i++, o primeiro valor será i[0]
    int i=-1;
    //loop do tipo do-while para fazer a leitura
    do
    {
        //incremento na variavel i
        i++;

        //lendo o caractere na posição de i
        scanf("%c", &frase[i]);

        //caractere recebe o retorno da funçao trocaEspaço
        frase[i] = trocaEspaco(frase[i]);

    }while(verificaFinalCaractere(frase[i]));

    //mostrando frase modificada
    printf("RESP:%s", frase);

    return 0;
}
