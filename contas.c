//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//função que le todos os dados necessários
void le_dados(float* somaProdutos, float* despesa);

//função que calcula o valor final que cabe a cada um
float calcula_porcentagem(float somaProdutos, float despesa);

//função principal
int main(void)
{
    float somaProdutos = 0, despesa = 0, pc;

    //lendo os dados necessários
    le_dados(&somaProdutos, &despesa);

    //calculando a parte qua cabe a cada um
    pc = calcula_porcentagem(somaProdutos, despesa);

    printf("\n---------------------------------- RESULTADO -----------------------------------------------\n");
    printf("Saulo - R$%.2f\nNeguinho - R$%.2f", pc, pc);

    return 0;
}

void le_dados(float* somaProdutos, float* despesa)
{
    float preco, dpz;
    int i, n, qtd;

    printf("---------------------------------- CALCULANDO PRODUTOS --------------------------------------\n\n");
    //lendo quantidade de produtos
    printf("Quantos produtos deseja somar? ");
    scanf("%d", &n);

    //lendo cada produto
    for(i = 0; i < n; i++)
    {
        //lendo dados
        printf("Digite a quantidade eo preço\n: ");
        scanf("%d %f", &qtd, &preco);

        //inrementando a soma com o valor da quantidade vezes o preço
        *somaProdutos += qtd * preco;
    }

    printf("\n---------------------------------- CALCULANDO DESPESA ---------------------------------------\n\n");
    //lendo quntidade para soma das despezas
    printf("Qual a quantidade de itens para somar na dispesa? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Digite o valor para somar\n: ");
        scanf("%f", &dpz);

        //incrementando despreza
        *despesa += dpz;
    }
}

float calcula_porcentagem(float somaProdutos, float despesa)
{
    float valorLiquido, cada;

    //calculando valor liquido
    valorLiquido = somaProdutos - despesa;

    //calculando a parte que cabe a cada
    cada = valorLiquido / 2;

    return cada;
}
