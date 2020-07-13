/*
(BOCA:L2_12) 
Problema: Faça um programa para substituir caracteres espaço ‘ ‘ por caracteres underline ‘_’ de uma frase. O programa deverá ler caracteres da entrada padrão (um por vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Saída: “RESP:” seguido da sequência de caracteres modificada.
*/

#include <stdio.h>
#include <stdlib.h>


//funçao que verifica o caractere final
int verificaFinalCaractere(char caractere)
{
    //caso o caractere seja . ! ou ? retornamos 1, caso contrario, 0
    if(caractere == 46 || caractere == 63 || caractere == 33)
    {
        return 1;
    }else
    {
        return 0;
    }   
}


//funçao que verifica se o caractere é um espaço, se sim, troca o mesmo por underline _
char trocaEspaco(char caractere)
{
    //caso o caractere seja um espaço em branco
    if(caractere == 32)
    {
        //caractere recebe underline
        caractere = 95;
    }

    //retornando caractere
    return caractere;
}


//funçao principal
int main()
{
    char frase[50];

    scanf("%[^\n]s", frase);
    setbuf(stdin, NULL);
    //fgets(frase, 50,  stdin);

    int i=0;
    while(i < 50)
    {
        if(verificaFinalCaractere(frase[i]))
        {
            break;
        }
        //caso contrario, o nosso caractere recebe o retorno da funçao trocaEspaço
        else
        {
            frase[i] = trocaEspaco(frase[i]);
        }
        i++;
    }

    //mostrando frase modificada
    printf("RESP:%s", frase);

    return 0;
}