/*
(BOCA:L3_5) Problema: Observe a seguinte propriedade que alguns números maiores que 1000 e menores que 9999 possuem:
Número: abcd
(ab) + (cd) = (ef)
𝑒𝑓∗𝑒𝑓 = abcd
Exemplo: 3025
30+25 = 55
55∗55 = 3025

a) A verificação da propriedade de um número deverá ser feita por uma função (a ser implementada) que receberá um número num e retornará verdadeiro caso num satisfaça a propriedade, ou falso caso contrário. A função deverá ter o seguinte cabeçalho: int Propriedade(int num);

 Entrada: Dois inteiros n e m (sendo n SEMPRE menor que m), contidos no intervalo (1000,9999). Ou seja, 1000 < n,m < 9999 e n<m.

 Saída: Como saída, seu programa deverá exibir os números maiores que n e menores que m que satisfaçam esta propriedade, separados por uma quebra de linha.*/

//função principal
#include <stdio.h>

//funçao que verifica a propriedade
int Propriedade(int num);

//funçao principal
int main()
{
    //inicio e fim do intervalo
    int n, m;

    //leitura dos dados
    scanf("%d %d", &n, &m);

    //como nao queremos considerar n, incrementamos o mesmo
    n++;

    //loop for de n, ate n menor do que m
    for (n; n < m; n++)
    {
        //caso o valor de retorno seja 1, entraremos automaticamente no if
        if (Propriedade(n))
            //mostrando o numero que satisfaz a propriedade
            printf("%d\n", n);
    }

    return 0;
}

//funçao que verifica a propriedade
int Propriedade(int num)
{
    //declaraçao de variaveis
    int ab, cd, ef, efAoQuadrado, num2;

    //cd é dado pelo resto da divisao de num por 100
    cd = num % 100;

    //num2 é dado por num - cd
    num2 = num - cd;

    //como agora num2 possui (00), ao final, podemos corta-los dividindo por 100, restando ab
    ab = num2 / 100;

    //ef é dado por ab + cd
    ef = ab + cd;

    //ef ao quadrado é dado por ef * ef
    efAoQuadrado = ef * ef;

    //caso efAoQuadrado seja == num, retornamos 1, se não 0
    return (efAoQuadrado == num) ? 1 : 0;
}
