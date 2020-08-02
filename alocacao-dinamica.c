//programa que calcula a media usando alocação dinamica

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//função que retorna a media
float media(int *notas, int qtd);

int main()
{
    int qtd, *notas;
    float mediaNotas;

    //lendo a quantidade de notas
    printf("Digite a quantidade de notas: ");
    scanf("%d", &qtd);

    //notas recebe o endereço de memória inicial da area alocada dinamicamente
    //OBS: agora, podemos trabalhar como se v fosse um vetor definido localmente
    notas = (int *)malloc(qtd*sizeof(int));

    //caso não haja espaço para alocar na memoria
    if(notas == NULL)
    {
        printf("Espaço insficiente!");

        return 1;
    }

    //lendo as notas
    for(int i = 0; i < qtd; i++)
    {
        printf("Digite a nota %d: ", i+1);
        scanf("%d", &notas[i]);
    }

    //calculando a media atraves da funçao
    mediaNotas = media(notas, qtd);

    //moatrando dados
    printf("A media das notas e: %f", mediaNotas);

    //liberando o espaço de memoria alocado
    free(notas);
    return 0;
}

float media(int *notas, int qtd)
{
    int soma = 0;

    //percorrendo vetor
    for(int i = 0; i < qtd; i++)
        //incrementando soma
        soma += notas[i];

    //retornando media
    return soma / (float)qtd;
}
