//importação de bibliotecas
#include <stdio.h>

//definindo estrutura para um ponto e definindo-a com o pseudônimo de 'Ponto'
typedef struct ponto
{
    float x;
    float y;
} Ponto;

//definindo estrutura para um circulo e setando-a com o pseudônimo de 'Circulo'
typedef struct circulo
{
    //definindio um ponto para as coordenadas do centro do circulo
    Ponto centro;
    float raio;
} Circulo;

//função que imprime valores de um circulo
void imprime(Circulo *c);

//função principal
int main(void)
{
    //declarando uma variável do tipo circulo
    Circulo c;
    
    //OBS: Quando definimos estruturas dentro de estruturas, devemos, para acessar as variaveis especificas, passar o caminho completo

    //lendo um circulo
    printf("Digite as coordenadas e o raio de um circulo: ");
    scanf("%f %f %f", &c.centro.x, &c.centro.y, &c.raio);

    //mostrando seus valores
    imprime(&c);
    return 0;
}

void imprime(Circulo *c)
{
    printf("Raio = %.2f\nx = %.2f\ny = %.2f", c->raio, c->centro.x, c->centro.y);
}
