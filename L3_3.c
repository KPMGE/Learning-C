/*(BOCA: L3_3) 
Problema: Faça um programa que imprima os números primos contidos em um intervalo n e m fornecidos pelo usuário.
a) A identificação do número primo deverá ser feita por uma função (a ser implementada) que receberá um número num e retornará verdadeiro se o número for primo e falso caso contrário. A função deverá ter o seguinte cabeçalho: int EhPrimo(int num);

Entrada: Seu programa deverá receber dois inteiros n e m, indicando o intervalo a ser avaliado. Considere que n e m formem um intervalo aberto, ou seja, n e m não precisam ser avaliados. Considere também que n sempre seja menor que m.

Saída: Como saída, o programa deverá exibir todos os números primos contidos no intervalo aberto (n,m). Todos os números exibidos deverão ser separados por um espaço e estarem numa mesma linha. O formato de saída deve ser seguido RIGOROSAMENTE.*/

#include <stdio.h>

//funçao que verifica se o numero é primo
int EhPrimo(int num);

//função principal
int main()
{
    //inicio e fim do intervalo(aberto)
    int n, m;

    //leitura dos dados
    scanf("%d%d", &n, &m);

    //incremento em n, pois o intervalo é aberto
    n++;

    //loop for de n ate n menor q m
    for (n; n < m; n++)
    {
        //se o numero for primo, teremos verdadeiro para o if, logo sera mostrado o valor na tela
        if (EhPrimo(n))
            printf("%d ", n);
    }

    return 0;
}

//funçao que verifica se o numero é primo
int EhPrimo(int num)
{
    int i = 2, primo = 0;

    //loop enquanto i for menor que o numero
    while (i < num)
    {
        //se o resto da divisao do numero por i for igual a 0, variavel primo incrementada
        if (num % i == 0)
            primo++;
        //incremento na variavel i
        i++;
    }

    //caso o numero seja primo é retornado o valor 1(verdadeiro), caso contrario, 0(falso)
    return (primo == 0) ? 1 : 0;
}
