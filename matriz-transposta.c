//programa que, dada uma matriz, calcula sua transposta

//importação de bibliotecas
#include <stdio.h>
//variavel para o tamanho da matriz
int n;

//função que calcula a transposta modificando matrizes definidas na função que chama
void calculaTransposta(int m, int n, float mat[][n], float trp[][n]);

//função principal
int main(void)
{
    //declaração de variaveis
    int colunas, linhas, i, j;

    //lendo as dimensões da matriz 
    printf("Digite a quantidade de linhas e colunas da matriz:");
    scanf("%d %d", &colunas, &linhas);

    //definindo matriz com as dimensões especificadas
    float matriz[linhas][colunas], transposta[linhas][colunas];

    //lendo matriz
    printf("Digite a matriz:\n");
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            scanf("%f", &matriz[i][j]);

    //calculando matriz transposta
    calculaTransposta(linhas, colunas, matriz, transposta);

    //mostrando a transposta
    printf("A matriz transposta e:\n\n");
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
            printf("%.1f ", transposta[i][j]);
        printf("\n");
    } 

    return 0;
}

void calculaTransposta(int m, int n, float mat[][n], float trp[][n])
{
    int i, j;

    //calculando a transposta
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            //invertendo linhas por colunas
            trp[j][i] = mat[i][j];
}
