/*
(BOCA:L2_14) 
Problema: Faça um programa para eliminar os caracteres espaço ‘ ‘ de uma frase. O programa deverá ler caracteres da entrada padrão (um por vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Saída: “RESP:” seguido da sequência de caracteres modificada.
*/

#include <stdio.h>
#include <string.h>


//funçao que verifica o caractere final
int verificaFinalCaractere(char caractere)
{
    //caso o caractere seja . ! ou ? retornamos 0, caso contrario, 1
    if(caractere == 46 || caractere == 63 || caractere == 33)
    {
        return 0;
    }else
    {
        return 1;
    }   
}


int ehEspaco(char caractere)
{
    if(caractere == 32)
    {
        return 1;
    }else
    {
        return 0;
    }  
}

//funçao principal
int main()
{
    int i=0;
    char frase[50];

    scanf("%[^\n]s", frase);
    setbuf(stdin, NULL);

    /*
     if(!verificaFinalCaractere(frase[i]))
        {
            break;
        }*/

    for(i; i<strlen(frase); i++)
    {
        if(frase[i] == ' ')
        {
            frase[i] = frase[i+1];
        }
    }

    printf("%s", frase);
    
    return 0;
}