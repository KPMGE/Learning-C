#include <stdio.h>
#include <stdlib.h>

int main(){
    int notas[3][3];
    float media, vetormedia[3];

    printf("digite as notas do aluno 1: ");
    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            scanf("%d", &notas[i][j]);
            media += notas[i][j];
        }
        media /= 3;
        vetormedia[i] = media;
        printf("digite as notas do aluno %d\n> ", i+2);
    }

    printf("\na matriz de notas e\n");
    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            printf("%d ", notas[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i < 3; i++){
        printf("\nA media do aluno %d e - %f\n", i+1, vetormedia[i]);
    }

    return 0;
}