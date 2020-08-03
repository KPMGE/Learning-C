//programa que calcula a transposta de uma matriz usando alucação dinâmica de um vetor que contem a matriz bidimensional


//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//função que calcula a matriz transposta
float* calculaTransposta(int linhas, int colunas, float *vetor_matiz);

//função principal
int main(void)
{
    int linhas, colunas, i, j;
    float *vetor_transposta;

    printf("Digite a quantidade de linha e colunas da matriz:\n> ");
    scanf("%d %d", &linhas, &colunas);

    //definindo vetor para alocar os elementos da matriz dinâmicamente
    float *vetor_matriz;

    //alocando um vetor do tamanho necessário para armazenar a matriz, ou seja, linhas*colunas
    vetor_matriz = (float *) malloc(linhas * colunas * sizeof(float));

    //OBS: para acessar os elementos usamos vetor[i * n + j] para acessar o elemento matriz[i][j]

    //lendo matriz
    printf("Digite a matriz:\n");
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            scanf("%f", &vetor_matriz[i * colunas + j]);


    //calculando a matriz transposta com a função
    vetor_transposta = calculaTransposta(linhas, colunas, vetor_matriz);

    //mostrando matriz transposta
    printf("A matriz transposta e:\n\n");
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
            //mostrando cada elemento da matriz
            printf("%.2f ", vetor_transposta[i * colunas + j]);

        //mostrando uma quebra de linha
        printf("\n");
    }

    //liberando memória alocada
    free(vetor_transposta);
    free(vetor_matriz);

    return 0;
}

float* calculaTransposta(int linhas, int colunas, float *vetor_matriz)
{
    //declaração de variáveis
    int i, j;
    float *vetor_transposta;

    //alocando o vetor que aramazenará a matriz transposta
    vetor_transposta = (float *) malloc(linhas * colunas * sizeof(float));

    //preenchendo o vetor-matriz, da matriz transposta
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            //vetor_transposta[j][i] = vetor_matriz[i][j]
            vetor_transposta[j * colunas + i] = vetor_matriz[i * colunas + j];


    //retornando ponteiro para o vetor_transposta
    return vetor_transposta;
}
