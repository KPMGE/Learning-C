#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

void push(int i);
int pop(void);

int *top, *p1, stack[SIZE];

int main(void){
    int value;

    top = stack; //top contem o topo da pilha
    p1 = stack;  //inicializa p1

    do{
        printf("Digite o value: ");
        scanf("%d", &value);

        if(value != 0){
            push(value);
        }
        else{
            printf("O value do topo e %d\n", pop());
        }
    }while(value != -1);
}

void push(int i){
    p1++;
    if(p1 == (top+SIZE)){
        printf("Estouro da pilha");
        exit(1);
    }
    *p1 = i;
}

int pop(void){
    if(p1 == top){
        printf("Estouro da pilha");
        exit(1);
    }
    p1--;
    return *(p1+1);
}
