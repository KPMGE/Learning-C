//programa que muda os valores das variáveis da função que chama com as operações
#include <stdio.h>

//função que captura os numeros e os ponteiros e os modifica
void SPD(int num1, int num2, int *soma, int *produto, int *divisao);

int main()
{
    int soma, produto, divisao;

    //passando os dois numeros e os endereços de memória das variávies locais, que serão modificadas
    SPD(10, 2, &soma, &produto, &divisao);

    //mostrando o valor das variávies locais, agora modificadad
    printf("Soma: %d\nProduto: %d\nDivisao: %d", soma, produto, divisao);
    return 0;
}

void SPD(int num1, int num2, int *soma, int *produto, int *divisao)
{
    //adicioconando um valor ao endereço de memória do ponteiro dado pelo resultado das operações
    *soma = num1 + num2;
    *produto = num1 * num2;
    *divisao = num1 / num2;
}
