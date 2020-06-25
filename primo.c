//importando bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Encontrando os numeros primos em um intervalo*/
int main(){
    //declaração de variaveis
	int n=0, m, primo=0, i=2, cont=0, escolha;
	
	do{
		printf("\n--------- Calculando numeros primos em um intervalo ---------\n\n");

		printf("digite os valores de inicio e final do intervalo('aberto')\n> ");
		//leitura dos dados
		scanf("%d%d", &n, &m);

		n += 1;

		printf("Os numeros primos neste intervalo sao: \n");
		//for do numero 1o numero digitado ate o ultimo ("intervalo aberto")
		for(n; n < m; n++){
			//loop enquanto o valor de i for menor que n
			while(i < n){
				//condição caso n seja divisivel por i, logo n não é primo
				if(n%i == 0){
					//variavel primo é incrementada em uma unidade
					primo++;
				}
				//variavel i do cabeçalho incrementada
				i++;
			}

			//apos a execução do loop, resetamos o valor de i
			i = 2;

			//caso a variavel primo seja 0, n não é divisivel por nenhum dos numeros anteriores, portanto n é primo
			if(primo == 0){
				cont++;
				printf("~\t%d\n", n);
			}

			//apos a comparação, resetamos a variavel primo
			primo = 0;
		}
		printf("Temos %d numeros primos neste intervalo", cont);

		printf("\nDeseja calcular novamente?(0 = N) ");
		scanf("%d", &escolha);
	}while(escolha != 0);

	return 0;
}