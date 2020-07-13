#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char unidade[1];
	float t, c, f;

	scanf("%f", &t);
	scanf("%s", &unidade[0]);
	
	if(strcmp(unidade, "f") == 0 || strcmp(unidade, "F") == 0){
		c = (5*(t - 32))/9;

		printf("%.2f(C)", c);
	}

	else if(strcmp(unidade, "c") == 0 || strcmp(unidade, "C") == 0){
		f = (9*t + 160) / 5;
		printf("%.2f(F)", f);
	}

	return 0;
}
