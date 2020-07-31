/*
(BOCA:L3_7) 
Problema: Dado as coordenadas x e y das extremidades inferior esquerda e superior direita de dois retângulos, calcule a área total ocupada por eles.

a) O cálculo da área total deverá ser realizado por uma função (a ser implementada) que receberá as coordenadas das extremidades de cada retângulo e retornará o resultado. A função deverá ter o seguinte cabeçalho: int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2); 

b) O cálculo da área de um retângulo deverá ser realizado por uma função (a ser implementada) que receberá as coordenadas das extremidades desse retângulo e retornará o resultado. A função deverá ter o seguinte cabeçalho: int area (int x1, int y1, int x2, int y2); 

Atenção: As coordenadas da extremidade inferior esquerda do primeiro retângulo serão sempre menores (ou iguais) que todas as outras. As coordenadas da extremidade superior direita do segundo retângulo serão sempre maiores (ou iguais) que todas as outras. Nenhum retângulo estará inteiramente contido dentro de outro.

• Entrada: duas linhas, uma para cada retângulo. Cada linha conterá 4 números inteiros representando as coordenadas x e y das extremidades inferior esquerda e superior direita, exatamente nessa ordem.

• Saída: “RESP:” seguido de um número inteiro representando a área total ocupada pelos dois retângulos.
*/

//importaçao das bibliotecas
#include <stdio.h>
#include <math.h>

//funçao que calcula a distancia entre dois pontos
int distanciaEntreDoisPontos(int x1, int y1, int x2, int y2);

//funçao que calcula a area de um unico retangulo
int area(int x1, int y1, int x2, int y2);

//funçao que calcula a area total dos dois retangulos
int area_total(int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2);

//funçao principal
int main(void)
{
    //declaraçao das variveis usadas
    int areaFinal;

    int r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2;

    //leitura das coordenadas do primeiro retangulo
    scanf("%d %d %d %d\n%d %d %d %d", &r1_x1, &r1_y1, &r1_x2, &r1_y2, &r2_x1, &r2_y1, &r2_x2, &r2_y2);

    //calculalndo area final com a funçao
    areaFinal = area_total(r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2);

    //mostrando resultado na tela
    printf("RESP:%d", areaFinal);

    return 0;
}

//funçao que calcula a distancia entre dois pontos
int distanciaEntreDoisPontos(int x1, int y1, int x2, int y2)
{
    //declaraçao das variveis usadas
    int distancia, xq, yq;

    //xq é dado pela diferença de x2 e x1
    xq = x2 - x1;

    //yq é dado pela diferença de y2 e y1
    yq = y2 - y1;

    //para calcular a distancia , fazemos a raiz quadrada de xq ao quadrado menos yq ao quadrado
    distancia = sqrt(pow(xq, 2) + pow(yq, 2));

    //retornando o valor da distancia
    return distancia;
}

//funçao que calcula a area de um unico retangulo
int area(int x1, int y1, int x2, int y2)
{
    //declaraçao das variveis usadas
    int d1, d2, area;

    //d1 é a distancia do ponto inferior esquerdo ate o ponto inferior direito, logo achamos uma aresta
    d1 = distanciaEntreDoisPontos(x1, y1, x2, y1);

    //d2 é a distancia do ponto inferior esquerdo ate o ponto superior esquerdo do retangulo, logo achamos a outra aresta
    d2 = distanciaEntreDoisPontos(x1, y1, x1, y2);

    //para calcular a area, basta multiplicar as arestas
    area = d1 * d2;

    //retornando area
    return area;
}

//funçao que calcula a area total dos dois retangulos
int area_total(int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2)
{
    //declaraçao das variveis usadas
    int area1, area2, total;

    //area1 é a area do primeiro retangulo
    area1 = area(r1_x1, r1_y1, r1_x2, r1_y2);

    //area2 é a area do segundo retangulo
    area2 = area(r2_x1, r2_y1, r2_x2, r2_y2);

    //area total é a soma das duas areas
    total = area1 + area2;

    //retornando area total
    return total;
}
