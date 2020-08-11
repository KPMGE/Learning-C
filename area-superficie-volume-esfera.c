//importação de bibliotecas
#include <stdio.h>
#include <math.h>

//definindo a constante PI
#define PI 3.14159

//função que calcula a área eo volume de uma esfera, modificando o valor das variáveis da função que chama com a função chamada usando ponteiros
void calc_esfera(float r, float *area, float *volume);

//função principal
int main(void)
{
    float r, area, volume;

    //lendo raio
    printf("digite o raio da esfera: ");
    scanf("%f", &r);

    //alterando o valor das variáveis area e volume indiretamente
    calc_esfera(r, &area, &volume);

    //mostrando resultados
    printf("Area: %.3f\nVolume: %.3f", area, volume);

    return 0;
}

void calc_esfera(float r, float *area, float *volume)
{
    *area = 4 * PI * pow(r, 2);
    *volume = 4 * PI * pow(r, 3) / 3;
}
