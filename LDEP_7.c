#include <stdio.h>

int main(){
	int n1, n2, n3;
	float media;

	scanf("%d %d %d", &n1, &n2, &n3);
	media = (n1 + n2 + n3)/(float)3;

	printf("Notas acima da média:");
	if (n1 >= media){ 
		printf(" %d", n1);
	}
	if (n2 >= media){ 
		printf(" %d", n2);
	}
	if (n3 >= media){ 
		printf(" %d", n3);
	}
	printf("!");
	
	return 0;
}
