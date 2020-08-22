#include <stdio.h>
#include <math.h>

int main(){
    int escolha;
    scanf("%d", &escolha);
    double soma=0, i=1, j=1;

    switch(escolha){
        case 1:
            for(i; i<=50; i++, j+=2){
                soma += j/i;
            }

            printf("%f", soma);
            break;

        case 2:
            i=50;
            for(j; j<=50; j++, i--){
                soma += pow(2, j)/i;
            }
            printf("%f", soma);
            break;

        case 3:
            for(j; j<=10; j++, i++){
                soma += j/pow(i, 2);
            }
            printf("%f", soma);
            break;

        default:
            return 0;
    }

    return 0;
}
