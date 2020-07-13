#include <stdio.h>

int main(){
    int n1, n2, mdc=0, mmc;
    int i=2;

    scanf("%d%d", &n1, &n2);

    for(i; i <= n2; i++){
        if(n1%i==0 && n2%i==0){
            mdc = i;
        }
    }

    for(i=2; i <= n2; i++){
        if(n1%i==0 && n2%i==0){
            mmc = i;
            break;
        }
    }

    printf("MMC = %d\nMDC = %d", mmc, mdc);

   return 0;
}