/*(BOCA: L3_4)
Problema: Faça um programa que imprima os números primos contidos em um intervalo n e m fornecidos pelo usuário seguidos por seus múltiplos até o final do intervalo.

a) A identificação do número primo deverá ser feita por uma função (a ser implementada) que receberá um número num e retornará verdadeiro se o número for primo e falso caso contrário. A função deverá ter o seguinte cabeçalho: int EhPrimo(int num);

b) A impressão dos múltiplos de um número deverá ser feita por uma função (a ser implementada) que receberá um número num e um número máximo max e imprimirá todos os múltiplos de num menores do que max. A função deverá ter o seguinte cabeçalho: void ImprimeMultiplos(int num, int max)

Entrada: Seu programa deverá receber dois inteiros n e m, indicando o intervalo a ser avaliado. Considere que n e m formem um intervalo aberto, ou seja, n e m não precisam ser avaliados. Considere também que n sempre seja menor que m.

Saída: Como saída, o programa deverá exibir todos os números primos contidos no intervalo aberto (n,m) e também seus múltiplos. Cada número primo do intervalo deverá ser impresso em uma linha separada, e seus múltiplos deverão ser todos impressos na linha seguinte separados por espaço. Caso o número primo não tenha múltiplos, imprima “ * “ na linha seguinte. Caso não haja primo no intervalo, não imprima nada.*/

#include <stdio.h>

//funçao que imprime os multiplos de num ate max
void ImprimeMultiplos(int num, int max);

//funçao que verifica se o numero é primo
int EhPrimo(int num);

//funçao principal
int main()
{
    //valores de inicio e fim do intervalo
    int n, m;

    //leitura dos dados
    scanf("%d%d", &n, &m);

    //incremento, pois nao queremos considerar n
    n++;

    //loop for de n ate n menor do que m
    for (n; n < m; n++)
    {
        //caso o numero seja primo, entra-se no if
        if (EhPrimo(n))
        {
            //mostrando o numero primo
            printf("%d\n", n);

            //chamada da funçao que imprime os multiplos do numero primo
            ImprimeMultiplos(n, m);
        }
    }

    return 0;
}

//funçao que imprime os multiplos de num ate max
void ImprimeMultiplos(int num, int max)
{
    int teste = 0, multiplo, i = 2;
    //loop indefinido
    while (1)
    {
        //multiplo recebe o valor de n, vezes o valor de i
        multiplo = num * i;

        //caso o multiplo seja maior ou igual que m, que é o numero fina, paramos o loop
        if (multiplo >= max)
            break;
        //caso contrario, mostramos o multiplo e incrementamos teste
        else
            printf("%d ", multiplo);
            teste++;

        //incremento a variavel i
        i++;
    }

    //caso o teste se mantenha como 0, sabemos que somente um loop foi executadoo, logo o numero em questao nao tem multiplos
    if (teste == 0)
        printf("*\n");
    //caso contrario apenas damos um espaço para a proxima exibiçao
    else
        printf("\n");

    //resetando a variavel teste, para realizar uma nova comparação
    teste = 0;
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
    if (primo == 0)
        return 1;
    else
        return 0;
}
