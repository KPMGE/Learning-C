//importação de bibliotecas
#include <stdio.h>
#include <math.h>

//definindo uma estrutura para o tipo ponto e usando o pseudônimo 'Ponto'
typedef struct ponto
{
    float x;
    float y;
} Ponto;

//função que calcula a área do polígono
float area_poligono(int n, Ponto *p);

//função principal
int main(void)
{
    int n, i;
    float area;

    //lendo a quantidade de pontos que formam o polígono
    printf("Digite a quantidade de pontos do poligono: ");
    scanf("%d", &n);

    //declarando vetor de estruturas para conter cada ponto
    Ponto poligono[n];

    //lendo pontos que formam o polígono
    for(i = 0; i < n; i++)
    {
        printf("Digite o ponto (x, y): ");
        scanf("%f %f", &poligono[i].x, &poligono[i].y);
    }

    //calculando a área do polígono
    //OBS: Como poligono é um vetor, não é necessário usar &, pois o nome sem índice já é um ponteiro para o primeiro elemento
    area = area_poligono(n, poligono);

    //mostrando resultados
    printf("A area do poligono e: %.2f", area);

    return 0;
}

float area_poligono(int n, Ponto *p)
{
    //declaração de variáveis
    int i, j;
    float area = 0;
    
    for(i = 0; i < n; i++)
    {
        //próximo índice, (incremento circular)
        j = (i + i) % n;

        //calculando area
        area += (p[j].x - p[i].x) * (p[i].y + p[j].y) / 2;
    }

    //retornando area em módulo
    return fabs(area);
}
