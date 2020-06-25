#include <stdio.h>
#include <stdlib.h>

int main(){
    float neguinho, frete, caixas, despezas, valorbruto, somabruto, qtdproduto, valorproduto;
    int num;

    valorbruto = 0;
    frete = 0;
    caixas = 0;

    printf("----------Produtos daqui----------\n");
    printf("Quantos produtos deseja calcular?\n>");
    scanf("%d", &num);

    int c=0;
    for(c; c < num; c++){
        printf("\nDigite o a quantidade de caixas do produto %d\n>", c+1);
        scanf("%f", &qtdproduto);
        printf("Digite o valor do produto %d\n>", c+1);
        scanf("%f", &valorproduto);

        somabruto = qtdproduto * valorproduto;

        valorbruto += somabruto;
    }

    printf("Digite o valor das caixas:\n> ");
    scanf("%f", &caixas);

    printf("Digite o valor do frete:\n> ");
    scanf("%f", &frete);

    printf("Digite o valor das despezas:\n> ");
    scanf("%f", &despezas);

    printf("\n\nO valor Bruto e: R$%.2f", valorbruto);

    valorbruto *= 0.5;
    caixas *= 0.5;
    frete *= 0.5;
    despezas *= 0.5;
    neguinho = valorbruto - (caixas + frete + despezas);

    printf("\nO valor liqido final que lhe cabe e: R$%.2f", neguinho);

    getch();

    return 0;
}
