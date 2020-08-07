//OBS: Para definir novos tipos, usamos o operador 'typedef' e uma declaração comum seja de variável ou estrutura


//importação de bibliotecas
#include <stdio.h>

//definindo uma estrutura para um ponto e chamando de Ponto
typedef struct ponto
{
    float x;
    float y;
} Ponto;

//definindo um novo tipo para uma variável do tipo unsigned long int
typedef unsigned long int Ulint;

//função principal
int main(void)
{
    //definindo uma variável do tipo ponto usando o pseudônimo
    Ponto p;

    //definindo uma variável do tipo unsigned long int com seu pseudônimo
    Ulint v;

    //atribuindo valores aos campos da estrutura
    p.x = 10;
    p.y = 8;

    //atribuindo valor a variável
    v = 200;

    //mostrando os valores
    printf("p.x = %.2f\np.y = %.2f\nv = %li", p.x, p.y, v);

    return 0;
}
