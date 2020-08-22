//Programa que verifica se um ponto está ou não dentro de um retangulo

//importação de bibliotecas
#include <stdio.h>

//criando estrutura para representar um ponto, e usando o pseudonimo 'Ponto'
typedef struct ponto
{
    float x;
    float y;
} Ponto;

//função que verifica se um ponto está ou não dentro de um dado retangulo
int dentroRet(Ponto* v1, Ponto* v2, Ponto* p);

//função principal
int main(void)
{
    //declaração de variáveis
    Ponto v1, v2, p;

    //lendo retangulo
    printf("Digite a extremidade inferior esquerda e superior direita do retangulo: ");
    scanf("%f %f %f %f", &v1.x, &v1.y, &v2.x, &v2.y);

    //lendo ponto para comparação
    printf("Digite um ponto qualquer: ");
    scanf("%f %f", &p.x, &p.y);

    //verificando se o ponto está ou não dentro do retangulo dado
    if(dentroRet(&v1, &v2, &p))
        printf("O ponto esta dentro do retangulo");
    else
        printf("O ponto nao esta dentro do retangulo"); 

    return 0;
}

int dentroRet(Ponto* v1, Ponto* v2, Ponto* p)
{
    //caso o valor de p em x e y seja menor que dos pontos que delimitam o retangulo, retornamos 1(TRUE), ou então 0(FALSE)
    if((v1->x > p->x || v2->x > p->x) && (v1->y > p->y || v2->y > p->y))
        return 1;
    else
        return 0;
}
