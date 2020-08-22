//programa para alocação de matrizes simétricas dinâmicamente na memória

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//função que cria um vetor de ponteiros para representar a matriz
float** cria_matriz(int n);

//função principal
int main(void)
{
    int n, i, j;
    float **matriz;

    //lendo tamanho da matriz
    printf("Digite o tamanho da matriz:\n> ");
    scanf("%d", &n);

    //matriz criada com alocação dinâmica por meio de um vetor de ponteiros
    matriz = cria_matriz(n);

    //lendo matriz
    printf("Digite a matriz:\n");
    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j++)
            scanf("%f", &matriz[i][j]);

    //mostrando matriz
    printf("Sua matriz e:\n");
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    //liberando memória
    //liberando cada vetor dentro do vetor de ponteiros
    for(i = 0; i < n; i++)
        free(matriz[i]);

    //liberando vetor de ponteiros
    free(matriz);
    return 0;
}

float** cria_matriz(int n)
{
    int i; 

    //vetor de ponteiros para matriz
    float **matriz;

    //alocando matriz
    matriz = (float **) malloc(n * sizeof(float *));
    for(i = 0; i < n; i++)
        matriz[i] = (float *) malloc((i + 1) * sizeof(float));

    //retornando matriz
    return matriz;
}
