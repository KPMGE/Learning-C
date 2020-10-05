#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num,num1, num2, num3, od, vf;

	scanf("%d%d", &num, &od);

	num1 = num;
	num %= 1000;
	num %= 100;
	num %= 10;
	vf = num;

	if(od == 1){
		if(vf % 2 == 0){
			printf("PAR");
		}
		else{
			printf("IMPAR");
		}
	}

	if(od == 2){
		num2 = num1 % 100;
		num2 -= vf;
		num2 *= 0.1;

		if(num2 % 2 == 0){
			printf("PAR");
		}
		else{
			printf("IMPAR");
		}
	}

	if(od == 3){
		num2 = num1 % 100;
		num3 = num1 - num2;
		num3 *= 0.01;

		if(num3 % 2 == 0){
			printf("PAR");
		}
		else{
			printf("IMPAR");
		}
	}

	return 0;
}

