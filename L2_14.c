/*
(BOCA:L2_14) 
Problema: Faça um programa para eliminar os caracteres espaço ‘ ‘ de uma frase. O programa deverá ler caracteres da entrada padrão (um por vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Saída: “RESP:” seguido da sequência de caracteres modificada.
*/


//importação de bibliotecas
#include <stdio.h>


//funçao que verifica o caractere final
int verificaFinalCaractere(char caractere)
{
    //caso o caractere seja . ! ou ? retornamos 0, caso contrario, 1
    if(caractere == '!'|| caractere == '?' || caractere == '.')
    {
        return 0;
    }else
    {
        return 1;
    }   
}


//função que retorna 1(verdadeiro), caso o caractere seja um espaço e 0(falso) caso contrário
int ehEspaco(char caractere)
{
    if(caractere == ' ')
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
    //declaração de variaveis
    int i=-1, j=0;
    char frase[50], frase2[50];

    //repetição até encontrar o caractere de fim da frase
    do
    {
        //incremento na variavel i
        i++;
     
        //leitura dos dados
        scanf("%c", &frase[i]);

        //caso o caractere não seja um espaço
        if(!ehEspaco(frase[i]))
        {
            //transcrevendo o caractere pra frase[j]
            frase2[j] = frase[i];

            //incremento na variavel j
            j++;
        }
    } while (verificaFinalCaractere(frase[i]));
    

    //mostrando frase final na tela
    printf("RESP:%s", frase2);
    
    return 0;
}
