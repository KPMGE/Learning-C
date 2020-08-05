//programa que calcuala todos os numeros primos em um intervalo aberto de n ate m

//importação de bibliotecas
#include <stdio.h>

//funçao que verifica se o numero é primo
int verificaPrimo(int n);

//função principal
int main(void){
	//inicio e fim do intervalo(aberto)
	int n, m, escolha=1, cont=0;

	do{
		//cabeçalho
		printf("-------------  calculando numeros primos num intervalo  -------------\n\nDigite os numeros de inicio e fim do intervalo(Aberto)\n> ");
		
		//leitura dos dados
		scanf("%d %d", &n, &m);

		//incremento em n, pois o intervalo é aberto
		n++;

		//loop for de n ate n menor q m
		for(n; n < m; n++){
			//se o numero for primo, teremos verdadeiro para o if, logo sera mostrado o valor na tela
			if(verificaPrimo(n)){
				printf("~  %d\n", n);
				cont++;
			}
		}
		
		//mostrando a quantidade de numeros primos contidos no intervalo
		printf("ha  %d  numeros primos neste intervalo!!", cont);
		//perguntando se o usuario deseja calcular novamente
		printf("\n\nQuer continuar?\nSim - AnyNumber\nNão - 0\n> ");
		scanf("%d", &escolha);
	}while(escolha != 0);

    return 0;
}

int verificaPrimo(int n)
{
    //variaveis para comparaçao
    int i = 2, primo = 0;

    //caso o numero seja diferente de 1 e -1
    if (n != 1 && n != -1 && n != 0)
    {
        //caso o numero seja negativo
        if (n < 0)
        {
            //variavel i recebe o valor de -2, o menor numero primo negativo
            i = -2;

            //enquanto o valor de i for maior que n
            while (n < i)
            {
                //caso o resto da divisao de n por i seja o, incrementamos a variavel primo
                if (n % i == 0)
                    primo++;

                //decremento em i
                i--;
            }

            //caso primo se mantenha como 0, sabemos que o numero é primo , logo retornamos 1(verdadeiro), caso contrario 0(falso)
            return (primo == 0) ? 1 : 0;
        }
        //caso o numero seja positivo
        else
        {
            //enquanto a variavel i for menor que n
            while (i < n)
            {
                //caso o resto da divisao de n por i seja igual a 0, variavel primo incrementada
                if (n % i == 0)
                    primo++;

                //incremento na variavel i
                i++;
            }

            //caso primo se mantenha como 0, sabemos que o numero é primo , logo retornamos 1(verdadeiro), caso contrario 0(falso)
            return (primo == 0) ? 1 : 0;
        }
    }
    //caso o numero seja 1 ou -1, apenas retornamos 0(falso), pois esses nao sao numeros primos
    else
        return 0;
}
