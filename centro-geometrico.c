//OBS: O centro geométrico é definido como um ponto cujas coordenadas x e y são a média dos valores de 
//x e de y, respectivamente

//importação de bibliotecas
#include <stdio.h>

//definindo estrutura para um ponto e usando como pseudônimo o nome 'Ponto'
typedef struct ponto
{
    float x;
    float y;
} Ponto;

//função que retorna o centro geométrico
Ponto centro_geometrico(int n, Ponto *v);

//função principal
int main(void)
{
    int n, i;
    Ponto c;

    printf("Quantos pontos deseja setar: ");
    scanf("%d", &n);

    //declarando um vetor de estruturas para cada ponto
    Ponto p[n];

    //lendo os pontos
    for(i = 0; i < n; i++)
    {
        printf("Digite o ponto (x, y): ");
        scanf(" %f %f", &p[i].x, &p[i].y);
    }

    //calculando centro geométrico
    c = centro_geometrico(n, p);

    //mostrando resultados
    printf("Centro geometrico: (%.2f, %.2f)", c.x, c.y);

    return 0;
}

Ponto centro_geometrico(int n, Ponto *v)
{
    int i;
    //declarando ponto que conterá o centro geométrio e inicializando-o
    Ponto centro = {0.0f, 0.0f};

    for(i = 0; i < n; i++)
    {
        centro.x += v[i].x;
        centro.y += v[i].y;
    }

    //calculando a media
    centro.x /= n;
    centro.y /= n;

    //retornando centro geométrico
    return centro;
}
