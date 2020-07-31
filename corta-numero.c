//Programa que, dado um numero , corta-o em seus algarismos
#include <stdio.h>
#include <math.h>

//função que retorna o tamanho do numero
int tamanhoNum(int num);

//função que retorna o algarismo na posicaoição dada
int algarismoNum(int num, int posicaoicao);

//função principal
int main(void)
{
    //declaração de variaveis
    int num, tamanho, algarismo, i;

    //leitura de dados
    printf("Digite o numero: ");
    scanf("%d", &num);
    
    tamanho = tamanhoNum(num);
    //mostrando tamanho 
    printf("O tamanho do numero e: %d\n", tamanho);

    //mostrando algarismos
    for(i = 1; i <= tamanho; i++)
    {
        algarismo = algarismoNum(num, i);
        printf("O algarismo na posicao %d e %d\n", i, algarismo);
    }

    return 0;
}

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

    //num3 recebe o numero dois com a primeira casa a menos
    num3 = num % (int)pow(10, posicaoicao-1);

    //algarismo recebe o numero2 - numero3, logo teremos um numero com o algarismo que queremos e 00.. após
    algarismo = num2 - num3;

    //cortando os zeros, restando somente o algarismo
    algarismo /= (int)pow(10, posicaoicao-1);

    return algarismo;
}