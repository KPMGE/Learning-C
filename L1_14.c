#include <stdio.h>
#include <stdlib.h>

int main(){
    //declara��o de variaveis
    int x1, y1, x2, y2, px, py, xc, yc;

    //leitura dos dados
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &px, &py);

    if(x2 > x1){
        xc = x1;
        x1 = x2;
        x2 = xc;
    }
    if(y2 > y1){
        yc = y1;
        y1 = y2;
        y2 = yc;
    }

    if(px <= x1 && px >= x2 && py <= y1 && py >= y2){
        printf("Dentro");
    }
    else{
        printf("Fora");
    }

	return 0;
}
