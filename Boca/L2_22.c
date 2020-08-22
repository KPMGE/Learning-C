/*(BOCA:L2_22) Problema: Dado um inteiro não-negativo, repetidamente some seus
dígitos, até que o resultado tenha somente um dígito.
Por exemplo: 29 = 2 + 9 = 11; 11 = 1 + 1 = 2.
•
• Entrada: um inteiro não negativo.
Saída: “RESP:” seguido de um inteiro correspondente à soma final.*/

//importação de bibliotecas
#include <stdio.h>
#include <math.h>


//função que retorna o tamanho do numero
int tamanhoNum(int num)
{
    int resto, i=1, tamanho = 0;

    //repetição enquanto o resto da divisão for diferente do numero
    while(resto != num)
    {
        //resto recebe o resto da disão de numero por 10 elevado a i
        resto = num % (int)pow(10, i);

        //incrementando tamanho e i
        tamanho++;
        i++;
    }
    
    return tamanho;
}


//função que retorna o algarismo na posicaoição dada
int algarismoNum(int num, int posicaoicao)
{
    int algarismo, num2, num3;

    //num2 recebe o numero integral até a casa especificada
    num2 = num % (int)pow(10, posicaoicao);

    //num3 recebe o numero com o tamanho de uma casa a menos que num2 
    num3 = num % (int)pow(10, posicaoicao-1);

    //algarismo recebe o numero2 - numero3, logo teremos um numero com o algarismo que queremos e 00.. após
    algarismo = num2 - num3;

    //cortando os zeros, restando somente o algarismo
    algarismo /= (int)pow(10, posicaoicao-1);

    return algarismo;
}


//função principal
int main()
{
    //declaração de variaveis
    int num, tamanho, algarismo, i, somaNum = 0;

    //leitura de dados
    scanf("%d", &num);
    
    //loop enquanto a soma for menor que 9
    do
    {
        //encontrando o tamanho do numero
        tamanho = tamanhoNum(num);
        //resetando a variavel somaNum
        somaNum = 0;

        for(i = 1; i <= tamanho; i++)
        {
            //obtendo o algarismo na posição de i
            algarismo = algarismoNum(num, i);
            //variavel incrementada com o valor do algarismo
            somaNum += algarismo;
        }
        
        //numero agora é a soma dos algarismos do numero anterior
        num = somaNum;
    }while(somaNum > 9);

    //mostrando valor final
    printf("RESP:%d", somaNum);

    return 0;
}
