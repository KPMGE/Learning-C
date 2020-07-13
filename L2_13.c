/*
(BOCA:L2_13)
Problema: Faça um programa para substituir letras minúsculas de uma frase por letras maiúsculas. O programa deverá ler caracteres da entrada padrão (um por vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

OBS: “YES - Presentation diferences” não é uma resposta válida para essa questão.

• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Saída: a sequência de caracteres modificada.
*/

//importação de bibliotecas
#include <stdio.h>


//funçao que verifica o caractere final
int verificaFinalCaractere(char caractere)
{
    //caso o caractere seja . ! ou ? retornamos 1, caso contrario, 0
    if(caractere == 46 || caractere == 63 || caractere == 33)
    {
        return 0;
    }else
    {
        return 1;
    }   
}


//funçao que retorna 1(verdadeiro) se a letra for minuscula e 0(falso) caso contrário
int verificaMinuscula(char letra)
{
    //caso a letra esteja entre 97 e 122 a mesma é minuscula
    if(letra >= 97 && letra <= 122)
    {
        return 1;
    }else
    {
        return 0;
    }
    
}


//funçao que retorna a propria letra se já maiusculo, ou caractere se não a transforma em maiuscula
char transformaMaiusculo(char letra)
{
    //caso a letra minuscula 
    if(verificaMinuscula(letra))
    {
        letra -= 32;
        return letra;
    }
    //caso maiuscula, ou qualquer outro caractere 
    else
    {
       return letra; 
    }
}


//funçao principal
int main()
{
    //declaraçao de variaveis
    char frase[50];
    int i=0;

    //leitura de dados
    scanf("%[^\n]s", frase);
    setbuf(stdin, NULL);

    //loop enquanto nao chegamos no final da frase
    while(verificaFinalCaractere(frase[i]))
    {    
        //transformamos a letra correspondente ao indice q estamos
        frase[i] = transformaMaiusculo(frase[i]);
        
        //incremento na variavel i
        i++;
    }


    //mostrando a frase na tela
    printf("%s", frase);

    return 0;
}