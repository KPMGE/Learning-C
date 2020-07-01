#include <stdio.h>

//funçao que verifica se o numero é primo
int EhPrimo(int num){
    int i=2, primo=0;

    //loop enquanto i for menor que o numero
    while(i < num){
        //se o resto da divisao do numero por i for igual a 0, variavel primo incrementada
        if(num%i == 0){
            primo++;
        }
        //incremento na variavel i
        i++;
    }

    //caso o numero seja primo é retornado o valor 1(verdadeiro), caso contrario, 0(falso)
    if(primo == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(){
	//inicio e fim do intervalo(aberto)
	int n, m, escolha=1, cont=0;

	do{
		//cabeçalho
		printf("-------------  calculando numeros primos num intervalo  -------------\n\nDigite os numeros de inicio e fim do intervalo(Aberto)\n> ");
		
		//leitura dos dados
		scanf("%d%d", &n, &m);

		//incremento em n, pois o intervalo é aberto
		n++;

		//loop for de n ate n menor q m
		for(n; n<m; n++){
			//se o numero for primo, teremos verdadeiro para o if, logo sera mostrado o valor na tela
			if(EhPrimo(n)){
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