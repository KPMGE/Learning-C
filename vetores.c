//programa que calcula a media de uma dada quantidade de notas usando vetores
#include <stdio.h>

int main()
{
    //variavel que guarda a quantidade de notas a ser digitada
    int qtd;

    //lendo a quantidade
    printf("Digite a quantidade de notas que deseja calcular: ");
    scanf("%d", &qtd);

    //declarando vetor para as notas do tamanho especificado
    int notas[qtd], i, soma = 0;
    float media;

    for(i = 0; i < qtd; i++)
    {
        //lendo valores das notas
        printf("Digite a %d nota: ", i+1);
        scanf("%d", &notas[i]);

        //soma incrementada com o valor de notas na posição de i
        soma += notas[i];
    }

    //media calculada pela soma sobre a quantidade de notas
    media = soma / (float)qtd;

    //mostrando os dados finais na tela
    printf("A media das notas e: %.2f", media);
    return 0;
}
