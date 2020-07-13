/*
(BOCA: P1_2016_Q3) Problema: Faça um programa para verificar a validade de um código de 4 caracteres, em que o primeiro caractere deve ser maiúsculo, o segundo deve ser um dígito, o terceiro deve ser uma vogal, e o quarto deve ser uma consoante minúscula.

 Entrada: 4 caracteres.
 Saída: O programa deverá imprimir “Invalido” se algum dos caracteres não respeitar as regras de construção do código, e deverá imprimir o próprio código em maiúsculo, caso contrário.
*/

//importaçao de bibliotecas
#include <stdio.h>
#include <ctype.h>


//funçao que verifica se o caractere é maiusculo
int verificaMaiusculo(char caractere)
{
    //caso o caractere seja menor ou igual que 90 e maior ou igual que 65, o mesmo é maiusculo
    if(caractere >= 65 && caractere <=90)
    {
        return 1;
    }else{
        return 0;
    }
}


//funçao que verifica se o digito é numero
int verificaDigito(char digito)
{
    //caso isdigit, o numero é primo
    if(isdigit(digito) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//funçao que verifica se o caractere é uma vogal
int verificaVogal(char caractere)
{
    //array contendo todas as vogais
    char vogais[11] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    //loop for percorendo cada vogal
    int c;
    for(c=0; c<10; c++)
    {
        //caso o caractere seja igual a vogal na posiçao de c, retornamos 1(verdadeiro)
        if(caractere == vogais[c])
        {
            return 1;
        }
    }

    //caso contrario, retornamos 0(falso)
    return 0;
}


//funçao que  verifica se o caractere é uma consoante minuscula
int verificaConsoanteMinuscula(char caractere)
{
    //caso o não vogal, temos uma consoante
    if(!verificaVogal(caractere))
    {
        //caso o caractere seja uma letra minuscula
        if(caractere >= 97 && caractere <=122)
        {
            return 1;
        }
        //caso contrario
        else
        {
            return 0; 
        }
    }
}


//funçao que verifica a validade do codigo
int verificaValidade(char c1, int digito, char v, char c)
{
    //caso a primeira letra seja maiuscula
    if(verificaMaiusculo(c1))
    {
        //caso o segundo elemento seja um digito
        if(verificaDigito(digito))
        {
            //caso o terceiro elemento seja uma vogal
            if(verificaVogal(v))
            {
                //caso o quarto elemento seja uma vogal minuscula
                if(verificaConsoanteMinuscula(c))
                {
                    //retornando 1(verdadeiro)
                    return 1;
                }
            }
        }
    }
    //caso contrario, retornar 0(falso)
    else
    {
        return 0;
    }
}


//funçao que transforma o caractere em maiusculo
char transformaMaiusculo(char caractere)
{
    //caso o caractere seja maiusculo apenas o retornamos
    if(verificaMaiusculo(caractere))
    {
        return caractere;
    }
    //caso contrario, diminuimos o mesmo em 32, dessa forma o mesmo ficará maiusculo
    else
    {
        caractere -= 32;
        return caractere;   
    }
    
}


//funçao principal
int main()
{
    //variaveis usadas
    char c1, digito, vogal, consoante, codigoFinal[4];

    //leituta dos dados
    scanf("%c %c %c %c", &c1, &digito, &vogal, &consoante);

    //caso a validade seja atestada
    if(verificaValidade(c1, digito, vogal, consoante))
    {
        //c1 recebe o valor da funçao transformaMaiusculo
        c1 = transformaMaiusculo(c1);
        //vogal recebe o valor da funçao transformaMaiusculo
        vogal = transformaMaiusculo(vogal);
        //consoante recebe o valor da funçao transformaMaiusculo
        consoante = transformaMaiusculo(consoante);

       /* //criando uma string para o codigo final
        codigoFinal[0] = c1;
        codigoFinal[1] = digito;
        codigoFinal[2] = vogal;
        codigoFinal[3] = consoante;

        //mostrando o código finalizado
        printf("%s", codigoFinal);*/

        printf("%c%c%c%c", c1, digito, vogal, consoante);

    }
    //caso contrario mostramos Invalido
    else{
        printf("Invalido");
    }

    return 0;
}