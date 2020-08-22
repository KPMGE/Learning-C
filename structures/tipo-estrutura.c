//importação de bibliotecas
#include <stdio.h>

//definindo estrutura para ponto
struct ponto
{
    float x;
    float y;
};

//função principal
int main(void)
{
    //declarando variável estrutura do tipo ponto
    struct ponto p;

    //lendo os valores e passando para a variável
    printf("Digite as coordenadas de um ponto qualquer (x, y): ");
    scanf("%f %f", &p.x, &p.y);

    //mostrando dados
    printf("O ponto e: (%.2f, %.2f)", p.x, p.y);

    return 0;
}
