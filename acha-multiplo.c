#include <stdio.h>

int main(){
    int m, n;

    scanf("%d%d", &n, &m);

    for(n; n<m; n++){
        printf("Numero - %d\n", n);

        int i=2, multi;
        while(1){
            multi = n*i;

            if(multi > m){
                break;
            }else{
                printf("%d\n", multi);
            }
            i++;
        }
    }

    return 0;
}