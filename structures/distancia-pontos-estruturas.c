//Programa que calcula a distância entre dois pontos


//importação de bibliotecas
#include <stdio.h>
#include <math.h>

//criando estrutura para um tipo ponto
struct ponto
{
    float x;
    float y;
};

//função que calcula a distância entre os dois pontos
float distancia(struct ponto *ponto1, struct ponto *ponto2);

//função que lê os pontos
void le_pontos(struct ponto *ponto1, struct ponto *ponto2);

//função principal
int main(void)
{
    float d;
    //variáveis para conter os dois pontos
    struct ponto p1, p2;
    
    //lendo os pontos
    le_pontos(&p1, &p2);

    //calculando a distancia
    d = distancia(&p1, &p2);

    //mostrando resultado
    printf("A distancia entre os dois pontos e: %.2f", d);

    return 0;
}

void le_pontos(struct ponto *ponto1, struct ponto *ponto2)
{
    //lendo ponto1
    printf("Digite o ponto 1: ");
    scanf("%f %f", &ponto1->x, &ponto1->y);

    //lendo ponto2
    printf("Digite o ponto 2: ");
    scanf("%f %f", &ponto2->x, &ponto2->y);
}

float distancia(struct ponto *ponto1, struct ponto *ponto2)
{
    //declração de variáveis
    float distancia, deltax, deltay;

    //calculando deltas
    deltax = ponto2->x - ponto1->x;
    deltay = ponto2->y - ponto1->y;

    //calculando distancia
    distancia = sqrt(pow(deltax, 2) + pow(deltay, 2));

    //retornando distancia
    return distancia;
}
