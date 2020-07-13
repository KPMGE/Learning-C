#include <stdio.h>

int main(){
	int num, div, resto;

	printf("digite o numero\n> ");
	scanf("%d", &num);
	printf("digite o o divisor\n> ");
	scanf("%d", &div);

	resto = num % div;

	printf("o resto da divisao inteira e %d", resto);

	return 0;
}
