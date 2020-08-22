//Programa que calcula a transposta de uma matriz usando alocação dinâmica por meio de um vetor de ponteitos



//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//função que calcula a matriz transposta
float** calculaTransposta(int linhas, int colunas, float **matriz);

//função principal
int main(void)
{
    //declaração de variávies
    int linhas, colunas, i, j;
    float **transposta;

    printf("Digite a quantidade de linha e colunas da matriz:\n> ");
    scanf("%d %d", &linhas, &colunas);

    //definindo vetor de ponteiros para alocar os elementos da matriz dinâmicamente
    float **matriz;

    //alocando o vetor de ponteiros do tamanho das linhas da matriz
    matriz = (float **) malloc(linhas* sizeof(float *));

    //fazendo cada ponteiro do vetor apontar para um vetor contendo as linhas da matriz
    for(i = 0; i < linhas; i++)
        matriz[i] = (float *) malloc(colunas * sizeof(float));

    //OBS: Após defiir a matriz dessa forma, como um vetor de ponteiros, podemos usar a notação usual
    //para acessar os elementos matriz[i][j]

    //lendo matriz
    printf("Digite a matriz:\n");
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            scanf("%f", &matriz[i][j]);


    //calculando a matriz transposta com a função
    transposta = calculaTransposta(linhas, colunas, matriz);

    //mostrando matriz transposta
    printf("A matriz transposta e:\n\n");
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
            //mostrando cada elemento da matriz
            printf("%.2f ", transposta[i][j]);

        //mostrando uma quebra de linha
        printf("\n");
    }

    //liberando memória alocada
    
    //Primeiro devemos liberar os vetores que representam as linhas da matriz
    for(i = 0; i < linhas; i++)
    {
        free(transposta[i]);
        free(matriz[i]);
    }

    //agora podemos liberar os vetores de ponteiros
    free(matriz);
    free(transposta);

    return 0;
}

float** calculaTransposta(int linhas, int colunas, float **matriz)
{
    //declaração de variáveis
    int i, j;
    
    //criando vetor de ponteiros para alocar a matriz
    float **transposta;

    //criando area de memoria para o vetor de ponteiros
    transposta = (float **) malloc(linhas * sizeof(float *));

    //fazendo cada ponteiro apontar para uma linha da matriz
    for(i = 0; i < linhas; i++)
        transposta[i] = (float *) malloc(colunas * sizeof(float));

    //calculando a matriz transposta
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            transposta[j][i] = matriz[i][j];

    //retornando a matriz transposta
    return transposta;
}
