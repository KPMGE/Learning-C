#include <stdio.h>

int main(){
	
	int l, c, i, j;

	scanf("%d %d", &l, &c);

	int soma=0, soma2=0, atual[l][c];
	
	for (i=0; i<l; i++){
		for(j=0; j<c; j++){
			scanf("%d", &atual[i][j]);
			soma += atual[i][j];
		}
		printf("%d\n", soma);
		soma2 += soma;
		soma = 0;
	}

	printf("%d\n", soma2);

	return 0;
}