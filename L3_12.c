/*
 * (BOCA: L3_12) Problema: Dado um inteiro não-negativo, repetidamente
some seus dígitos, até que o resultado tenha somente um dígito. A cada
soma, o valor deverá ser impresso e após ele, deverá ser impresso se o
número é ímpar ou par, e se ele é primo.

a) Seu programa deve conter a função int somadosdigitos(int n); que
retorna a soma dos dígitos do número n.
b) Seu programa deve conter a função void parImpar(int n); que
imprime Par se n for par ou Impar se n for ímpar.

d) Seu programa deve conter a função void valorPrimo(int n); que
imprime Nao e primo se n não for primo ou Primo se n for primo.

• Entrada: um inteiro não negativo
• Saída: o valor de cada soma, seguido pela identificação de que se o
número é par ou ímpar. Se for par, deve imprimir: Par, se for ímpar,
imprimir: Impar. Se for primo: Primo, caso não: Nao e primo.
 */

//importação de bibliotecas
#include <stdio.h>
#include <math.h>

//função que imprime par ou impar
void parImpar(int n)
{
    //caso o numero seja divisível por 2 é par, se não é impar
    if(n % 2 == 0)
    {

        printf("Par ");
    }
    else
    {
        printf("Impar ");
    }
}

//função que verifica se o numero é primo
int verificaPrimo(int n)
{
    int primo = 0, i;

    //loop do menor primo até o numero anterior a n
    for(i = 2; i < n; i++)
    {
        //caso n seja divisível por i, incrementamos primo
        if(n % i == 0)
        {
            primo++;
        }
    }

    //caso a variável primo não se altere, o número só é divisivel por ele ou por 1, logo, é primo
    if(primo == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//função que imprime os primos
void valorPrimo(int n)
{
    //caso primo, mostramos Primo, caso contrário, Nao e Primo
    if(verificaPrimo(n))
    {
        printf("Primo");
    }
    else
    {
        printf("Nao e Primo");
    }
}

//função que retorna o tamanho do numero(casas decimais)
int tamanhoNum(int n)
{
    int tamanho = 0, resto, i = 1;

    //enquanto o resto da divisão for diferente do próprio numero
    while(resto != n)
    {
        //resto é dado por 10^i
        resto = n % (int)pow(10, i);

        //incrementando tamanho e i
        tamanho++;
        i++;
    }

    return tamanho;
}

//função que retorna o algarismo de um numero na posição dada
int algarismoNum(int n, int posicao)
{
    int algarismo, n2, n3;

    //n2 recebe o numero cortando ate o algarismo que queremos
    n2 = n % (int)pow(10, posicao);
    
    //n3 recebe os numero depois desse algarismo
    n3 = n % (int)pow(10, posicao-1);

    //algarismo recebe o numero com o algarismo e 000.. depois
    algarismo = n2 - n3;

    //eliminando os zeros, por divisão 
    algarismo /= (int)pow(10, posicao-1);

    return algarismo;
}

//função que calcula a soma dos digitos
int somadosdigitos(int n)
{
    int i, tamanho, algarismo, soma = 0;

    //achando o tamanho do numero em casas decimas
    tamanho = tamanhoNum(n);

    for(i = 1; i <= tamanho; i++)
    {
        //algarismo recebe o retorno da função algarismoNum
        algarismo = algarismoNum(n, i);

        //soma incrementada com o algarismo
        soma += algarismo;
        
        //resetando algarismo
        algarismo = 0;
    }
    
    return soma;
}

//função principal
int main()
{
    unsigned int valor, soma;
    
    //leitura de dados
    scanf("%d", &valor);

    //enquanto a soma dos digitos for maior que 9(maior numero de uma casa)
    do
    {
        //calculando a soma
        soma = somadosdigitos(valor);

        //mostrando dados
        printf("%d ", soma);
        parImpar(soma);
        valorPrimo(soma);
        printf("\n");

        valor = soma;
    }while(soma > 9);

    return 0;
}
