//Programa que, dado um ponto, verifica se o mesmo está dentro de um círculo


//importação de bibliotecas
#include <stdio.h>
#include <math.h>

//estrutura para o tipo ponto, com o nome 'Ponto'
typedef struct ponto
{
    float x;
    float y;
} Ponto;

//estrutura para um tipo circulo, com o nome 'Circulo'
typedef struct circulo
{
    //definindo um ponto para o centro do circulo
    Ponto centro;
    //definindo raio
    float raio;
} Circulo;

//função que verifica se um ponto está dentro de um circulo
int dentro_circulo(Circulo *c, Ponto *p);

//função que calcula a distancia entre dois pontos
float distancia_pontos(Ponto *p1, Ponto *p2);

//função principal
int main(void)
{
    //declaração de variáveis
    Ponto  p;
    Circulo c;

    //lendo circulo
    printf("Digite as coordenadas do centro de um circulo e seu raio:\n");
    scanf("%f %f %f", &c.centro.x, &c.centro.y, &c.raio);

    //lendo ponto
    printf("Digite um ponto: ");
    scanf("%f %f", &p.x, &p.y);

    //caso o ponto esteja dentro do circulo
    if(dentro_circulo(&c, &p))
        printf("O ponto esta dentro do circulo"); 
    else
        printf("O ponto esta fora do circulo");

    return 0;
}

float distancia_pontos(Ponto *p1, Ponto *p2)
{
    //declaração de variáveis
    float distancia, Dx, Dy;

    //calculando delta em x
    Dx = p2->x - p1->x;

    //calculando delta em y
    Dy = p2->y - p1->y;

    //calculando a distancia
    distancia = sqrt(pow(Dx, 2) + pow(Dy, 2));

    //retornando distancia
    return distancia;
}

int dentro_circulo(Circulo *c, Ponto *p)
{
    //caso a distanicia entre o centro do circulo e o ponto seja menor que o raio, o ponto esta no circulo
    if(distancia_pontos(p, &c->centro) < c->raio)
        return 1;
    else
        return 0;
}


