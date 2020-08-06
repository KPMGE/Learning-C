//(BOCA) - L5_1


//importação de bibliotecas
#include <stdio.h>
#include <math.h>

//função que retorna a maior nota
int maiorNota(int *notas, int qtd);

//função que retorna a menor nota
int menorNota(int *notas, int qtd);

//função que soma todas as notas
int somaNotas(int *notas, int qtd);

//função que calcula a media em uma dada quantidade
float calculaMedia(int soma, int qtd);

//função que verifica se acima da media
int acimaDaMedia(int *notas, int qtd, float media);

//função que retorna o numero de alunos reprovados
int achaReprovados(int *notas, int qtd);

//função que calcula o desvio padrão
float calculaDesvioPadrao(int *notas, int qtd, float media);

//função principal
int main(void)
{
    //declaração de variaveis
    int qtd, i, soma, acimaM, reprovados, maiorN, menorN;
    float media, desvioP;  

    //lendo quantidade de notas
    scanf(" %d", &qtd);

    //declarando vetor com o tamanho setado
    int notas[qtd];

    //lendo notas
    for(i = 0; i < qtd; i++)
        scanf("%d", &notas[i]);
    
    //calculando a soma das notas
    soma = somaNotas(notas, qtd);

    //calculando media
    media = calculaMedia(soma, qtd);

    //calculando maior nota
    maiorN = maiorNota(notas, qtd);

    //calculando menor nota
    menorN = menorNota(notas, qtd);

    //calculando quantidade de alunos acima da media
    acimaM = acimaDaMedia(notas, qtd, media);

    //calculando o numero de alunos reprovados
    reprovados = achaReprovados(notas, qtd);

    //calculando desvio padrão
    desvioP = calculaDesvioPadrao(notas, qtd, media);

    //mostrando resultados
    printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d", menorN, maiorN, media, desvioP, acimaM, reprovados);

    return 0;
}

int maiorNota(int *notas, int qtd)
{
    int i, maior = 0;

    //encontrando a maior nota
    for(i = 0; i < qtd; i++)
        if(notas[i] > maior)
            maior = notas[i];

    //retornando-a
    return maior;
}

int menorNota(int *notas, int qtd)
{
    int i, menor = notas[0];

    //encontrando a menor nota
    for(i = 0; i < qtd; i++)
        if(notas[i] < menor)
            menor = notas[i];

    //reotornando menor nota
    return menor;
}

int somaNotas(int *notas, int qtd)
{
    int i, soma = 0;

    //calculando a soma das notas
    for(i = 0; i < qtd; i++)
        soma += notas[i];

    return soma;
}

float calculaMedia(int soma, int qtd)
{
    //calculando a media
    return soma / (float)qtd;
}

int acimaDaMedia(int *notas, int qtd, float media)
{
    int i, acima = 0;

    //calculando a quantidade de alunos acima da media
    for(i = 0; i < qtd; i++)
        if(notas[i] > media)
            acima++;

    //retornando quantidade de alunos acima da media
    return acima;
}

int achaReprovados(int *notas, int qtd)
{
    int i, reprovados = 0;

    //percorrendo notas
    for(i = 0; i < qtd; i++)
        if(notas[i] < 70)
            reprovados++;

    //retornando numero de alunos reprovados
    return reprovados;
}

float calculaDesvioPadrao(int *notas, int qtd, float media)
{
    int i;
    float desvioPadrao, somatorio = 0;

    //calculando somatorio 
    for(i = 0; i < qtd; i++)
        somatorio += pow((notas[i] - media), 2);

    //calculando desvio padrao
    desvioPadrao = sqrt((1.0f / qtd) * somatorio);

    //retornando desvio padrao
    return desvioPadrao;
}
