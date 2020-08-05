/*
(BOCA:L2_18)
 Problema: Com dificuldade para estudar Álgebra Linear,
Padi decidiu fixar os conceitos da disciplina fazendo programas de
computador com a matéria. Para começar, quis fazer um programa
que, dado o tamanho da matriz e seus valores, que nunca são iguais,
calculasse o maior valor e imprimisse a posição dele na matriz.
Também com dúvidas em Programação, Padi agora pede sua ajuda e
você deve implementar o código para depois tirar as dúvidas do código
dele.

Entrada: uma linha com os valores L (1 <= L <= 100) e C (1 <= C <=
100), representando o tamanho da matriz em linhas e colunas,
respectivamente. Depois, L linhas com C valores V (-32767 <= V <=
32767) cada.

Saída: o maior valor V da matriz, seguido
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//variável global para a coluna da matriz
int c;

//função que retorna um vetor com o valor do maior elemento e os valores da linha e coluna, respectivamente
int* maior_valor(int matriz[][c], int l, int c);

//função principal
int main(void)
{
    //declaração de variaveis
    int l, i, j, *maior;

    //leitura das dimensões da matriz
    scanf("%d %d", &l, &c);

    //definição da matriz
    int matriz[l][c];

    //lendo matriz
    for(i=0; i < l; i++)
        for(j=0; j < c; j++)
            //leitura do elemento da matriz na posição i, j
            scanf("%d", &matriz[i][j]);
            
    //encontrando o maior valor
    maior = maior_valor(matriz, l, c);

    //mostrando resultados
    printf("%d (%d, %d)", maior[0], maior[1], maior[2]);
    
    //liberando memória alocada
    free(maior);

    return 0;
}

int* maior_valor(int matriz[][c], int l, int c)
{
    //declaração de variáveis
    int i, j;

    //ponteiro para o vetor que armazena o maior valor e suas coordenadas
    int *maior;

    //alocando vetor dinâmicamente
    maior = (int *) malloc(3 * sizeof(int));

    //inicializando com o valor 0 na primeira posição
    maior[0] = 0;

    //percorrendo matriz
    for(i = 0; i < l; i++)
        for(j = 0; j < c; j++)
        {
            //capturando o endereço do maior elemento
            if(matriz[i][j] > maior[0])
            {
                maior[0] = matriz[i][j];
                maior[1] = i + 1;
                maior[2] = j + 1;
            }
        }

    //retornando maior elemento
    return maior;
}
