/*Encontrando os numeros primos em um intervalo*/
#include <stdio.h>

int main(){
    //declaração de variaveis
	int n, m, primo=0, i=2;

    //leitura dos dados
	scanf("%d%d", &n, &m);

	n++;

    //for do numero 1o numero digitado ate o ultimo ("intervalo aberto")
	printf("RESP:");
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
			printf("%d ", n);
		}

        //apos a comparação, resetamos a variavel primo
		primo = 0;
	}
	return 0;
}
