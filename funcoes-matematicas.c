//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//função que calcula a matriz transposta
float** calculaTransposta(int linhas, int colunas, float **matriz);

//funçao que calcula a distancia entre dois pontos
float distanciaEntreDoisPontos(int x1, int x2, int y1, int y2);

//funçao que calcula as raizes de uma funçao do segundo grau
void calculaBaskara(int a, int b, int c);

//funçao que verifica se o numero é primo
int verificaPrimo(int num);

//funçao que soma N numeros
float somaNumeros(int num);

//funçao principal
int main(void)
{
    //declaração de variáveis
    int escolha, num, qtd, x1, x2, y1, y2, i, j, colunas, linhas;
    float a, b, c, **matriz, **transposta;

    //escolha do usuario
    printf("O que deseja fazer?\n1 - calcular baskara\n2 - verificar se um numero e primo\n3 - somar N numeros\n4 - calcular a distancia entre dois pontos\n5 - calcular a transposta de uma matriz\n> ");
    scanf("%d", &escolha);

    //menu dada a opçao escolhida
    switch (escolha)
    {

    //caso opçao 1 escolhida
    case 1:
        printf("digite o valor de A\n> ");
        scanf("%f", &a);

        printf("digite o valor de B\n> ");
        scanf("%f", &b);

        printf("digite o valor de C\n> ");
        scanf("%f", &c);

        calculaBaskara(a, b, c);

        break;

    //caso opçao 2 escolhida
    case 2:
        printf("digite o numero\n> ");
        scanf("%d", &num);

        verificaPrimo(num);

        break;

    //caso opçao 3 escolhida
    case 3:
        printf("digite a quantidade de numeros que deseja somar:  ");
        scanf("%d", &qtd);
        somaNumeros(qtd);

        break;

    //caso opçao 4 escolhida
    case 4:
        //lendo ponnto 1
        printf("digite o ponto 1\n> ");
        scanf("%d %d", &x1, &y1);

        //lendo ponto 2
        printf("Digite o ponto 2\n> ");
        scanf("%d %d", &x2, &y2);

        //chamando a função para calcular a distância
        distanciaEntreDoisPontos(x1, x2, y1, y2);

        break;

    //caso opção 5 escolhida
    case 5:
        //lendo a quantidade de linhas e colunas
        printf("Digite a quantidade de linhas e colunas da matriz:\n> ");
        scanf("%d %d", &linhas, &colunas);

        //alocando o vetor de ponteiros do tamanho das linhas da matriz
        matriz = (float **) malloc(linhas* sizeof(float *));

        //fazendo cada ponteiro do vetor apontar para um vetor contendo as linhas da matriz
        for(i = 0; i < linhas; i++)
            matriz[i] = (float *) malloc(colunas * sizeof(float));

        //OBS: Após defiir a matriz dessa forma, como um vetor de ponteiros, podemos usar a notação usual
        //para acessar os elementos matriz[i][j]

        //lendo matriz
        printf("Digite a matriz:\n");
        for(i = 0; i < linhas; i++)
            for(j = 0; j < colunas; j++)
                scanf("%f", &matriz[i][j]);


        //calculando a matriz transposta com a função
        transposta = calculaTransposta(linhas, colunas, matriz);

        //mostrando matriz transposta
        printf("A matriz transposta e:\n\n");
        for(i = 0; i < linhas; i++)
        {
            for(j = 0; j < colunas; j++)
                //mostrando cada elemento da matriz
                printf("%.2f ", transposta[i][j]);

            //mostrando uma quebra de linha
            printf("\n");
        }

        //liberando memória alocada
        //Primeiro devemos liberar os vetores que representam as linhas da matriz
        for(i = 0; i < linhas; i++)
        {
            free(transposta[i]);
            free(matriz[i]);
        }

        //agora podemos liberar os vetores de ponteiros
        free(matriz);
        free(transposta);

        break;

    //caso nenhuma das anteriores
    default:
        printf("Opcao invalida!!");
        break;
    }

    return 0;
}

//função que calcula a matriz transposta
float** calculaTransposta(int linhas, int colunas, float **matriz)
{
    //declaração de variáveis
    int i, j;
    
    //criando vetor de ponteiros para alocar a matriz
    float **transposta;

    //criando area de memoria para o vetor de ponteiros
    transposta = (float **) malloc(linhas * sizeof(float *));

    //fazendo cada ponteiro apontar para uma linha da matriz
    for(i = 0; i < linhas; i++)
        transposta[i] = (float *) malloc(colunas * sizeof(float));

    //calculando a matriz transposta
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            transposta[j][i] = matriz[i][j];

    //retornando a matriz transposta
    return transposta;
}

//funçao que calcula a distancia entre dois pontos
float distanciaEntreDoisPontos(int x1, int x2, int y1, int y2)
{
    //declaração de variáveis
    int  deltax, deltay;
    float distancia;

    //calculando delta em x e y
    deltax = x2 - x1;
    deltay = y2 - y1;

    //calculando a distância
    distancia = sqrt(pow(deltax, 2) - pow(deltay, 2));

    //mostrando resultado
    printf("Distancia: %.2f", distancia);

    //retornando resultado
    return distancia;
}

//funçao que calcula as raizes de uma funçao do segundo grau
void calculaBaskara(int a, int b, int c)
{
    float delta, raiz1, raiz2;

    //calculando o valor de delta
    delta = pow(b, 2) - 4 * a * c;

    //caso delta seja menor que 0, nao ha raizes reis
    if (delta < 0)
        printf("nao ha raizes reais!!");

    //do contrario, calculamos as raizes
    else
    {
        raiz1 = (-b + sqrt(delta)) / 2 * a;
        raiz2 = (-b - sqrt(delta)) / 2 * a;

        printf("R1: %.2f\n", raiz1);
        printf("R2: %.2f", raiz2);
    }
}

//funçao que verifica se o numero é primo
int verificaPrimo(int num)
{
    //variaveis declaradas
    int primo = 0, i = 2;

    //dividindo o numero por todos os numeros menores que ele começando por 2
    while (i < num)
    {
        if (num % i == 0)
            //caso divisivel por algum numero , variavel primo incrementada
            primo++;

        //incremento a variavel i
        i++;
    }

    //caso nao divisivel por nenhum dos numeros, primo
    if (primo == 0)
        printf("o numero e primo!");
    else
        printf("o numero nao e primo!!");
}

//funçao que soma N numeros
float somaNumeros(int num)
{
    float soma, n;

    //loop for ate o num especificado
    for (int i = 0; i < num; i++)
    {
        //lendo o valor a ser somado
        printf("digite o numero\n> ");
        scanf("%f", &n);

        //valor incrementado a soma
        soma += n;
    }

    //mostrando a soma e retornando-a
    printf("A soma e :  %.2f", soma);
    return soma;
}
