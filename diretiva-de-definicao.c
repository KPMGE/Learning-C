//programa que calcula a área de um circulo usando uma constante simbólica PI,
//gerada por uma diretiva de definição

//importação de bibliotecas
#include <stdio.h>
#include <math.h>

//definindo a constante PI
#define PI 3.14159F

//função que calcula a área de um círculo de raio R
float areaCirculo(int R);

//função principal
int main()
{
    //declaração de variáveis
    int raio;
    float area;

    //lendo os dados
    printf("Digite o raio do circulo: ");
    scanf("%d", &raio);

    //calculando a área com intermédio da função
    area = areaCirculo(raio);

    //mostrando resultados
    printf("A area e: %f", area);
    return 0;
}

//função que calcula a área de um circulo com raio R
float areaCirculo(int R)
{
    float area = PI * pow(R, 2);

    return area;
}
