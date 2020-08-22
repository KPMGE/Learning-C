//problema 10 maratona de programação - 2019
//
/*Vinicius leva muito a sério seu condicionamento fı́sico e, diariamente às 6h da manhã, chova ou faça
sol, no verão e no inverno, ele corre no entorno de uma lagoa. Ao longo da pista de corrida existem
N placas igualmente espaçadas. Para não desanimar do exercı́cio, Vinicius conta o número de placas
pelas quais ele já passou e verifica se ele já correu pelo menos 10%, pelo menos 20%, . . . , pelo menos
90% do percurso.
Vamos ajudar o Vinicius, calculando para ele o número de placas que ele precisa contar para ter
completado pelo menos 10%, 20%, . . . , 90% da corrida, dados o número de voltas que ele pretende
correr e o número total de placas ao longo da pista.
Por exemplo, suponhamos que Vinicius queira dar 3 voltas e o número de placas seja 17. Então,
para garantir ter corrido pelo menos 30% do percurso, ele precisa contar 16 placas. Para garantir pelo
menos 60%, ele precisa contar 31 placas.

Entrada
A entrada consiste de uma única linha que contém dois inteiros, V e N (1 ≤ V, N ≤ 10 4 ), onde V
é o número pretendido de voltas e N é o número de placas na pista.
Saı́da

Seu programa deve produzir uma única linha com nove inteiros representando os números de placas
que devem ser contadas para garantir o cumprimento, respectivamente, de 10%, 20%, . . . , 90% da
meta.*/

//importação de bibliotecas
#include <stdio.h>

//função que calcula a quantidade de placas dada a porcentagem
int quantidadePlacas(unsigned int v, unsigned int n, int pc);

//função que arredonda o numero, sempre para cima
int arredondaNum(float num);

//função principal
int main(void)
{
    //declaração de variáveis
    unsigned int v, n;
    int i, resultado[9], pc = 10;

    //leitura dos dados
    scanf("%d %d", &v, &n);

    //calculando a quantidade para cada porcentagem e mostrando
    for(i = 0; i < 9; i++, pc += 10)
    {
        resultado[i] = quantidadePlacas(v, n, pc);
        printf("%d ", resultado[i]);
    }

    return 0;
}

int arredondaNum(float num)
{
    //declaração de variáveis
    int parteInt;
    float parteDecimal;

    //separando somente a parte inteira do numero
    parteInt = (int)num;

    //dividindo o numero por sua parte inteira
    parteDecimal = num - parteInt;

    //caso a divisão dê um numero maior que 0, arredondamos o numero, usando o operador de incremento
    if(parteDecimal > 0)
        parteInt++;

    //retornando o numero inteiro convertido ou não
    return parteInt;
}

int quantidadePlacas(unsigned int v, unsigned int n, int pc)
{
    //declaração de variáveis
    int  totalPercurso;
    float qtdPlacas, pcDecimal;

    //porcentagem em decimal
    pcDecimal = (float)pc / 100;

    //calculando o percurso total
    totalPercurso = n * v;

    //quantidade de placas, dada a porcentagem
    qtdPlacas = totalPercurso * pcDecimal;

    //arredondando pra cima, ou mantendo o numero caso inteiro
    qtdPlacas = arredondaNum(qtdPlacas);

    //retornando a quantidade de placas
    return (int)qtdPlacas;
}

