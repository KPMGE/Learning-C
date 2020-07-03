//importaçao de bibliotecas
#include <stdio.h>


//funçao que verifica se o numero é negativo ou nao
int verificaNegativo(int n){
    //caso numero menor que 0, retornamos 1(verdadeiro), caso contrario 0(falso)
    if(n < 0){
        return 1;
    }else{
        return 0;
    }
}


//funçao que verifica se o numero é primo
int verificaPrimo(int n){
    //variaveis para comparaçao
    int i=2, primo=0;

    //caso o numero seja diferente de 1 e -1
    if(n != 1 && n != -1 && n != 0){
        //caso o numero seja negativo
        if(verificaNegativo(n)){
            //variavel i recebe o valor de -2, o menor numero primo negativo
            i = -2;

            //enquanto o valor de i for maior que n
            while(n < i){
                //caso o resto da divisao de n por i seja o, incrementamos a variavel primo
                if(n%i == 0){
                    primo++;
                }

                //decremento em i
                i--;
            }

            //caso primo se mantenha como 0, sabemos que o numero é primo , logo retornamos 1(verdadeiro), caso contrario 0(falso)
            if(primo == 0){
                return 1;
            }else{
                return 0;
            }
        }
        
        //caso o numero seja positivo
        else{
            //enquanto a variavel i for menor que n
            while(i < n){
                //caso o resto da divisao de n por i seja igual a 0, variavel primo incrementada
                if(n%i == 0){
                    primo++;
                }

                //incremento na variavel i
                i++;
            }

            //caso primo se mantenha como 0, sabemos que o numero é primo , logo retornamos 1(verdadeiro), caso contrario 0(falso)
            if(primo == 0){
                return 1;
            }else{
                return 0;
            }
        }
    }
    
    //caso o numero seja 1 ou -1, apenas retornamos 0(falso), pois esses nao sao numeros primos
    else{
        return 0;
    }
}


//funçao que transforma o numero no proximo primo, caso o numero nao seja primo e deixa o se ele ja for 
int transformaPrimo(int n){
    //variavel com o menor primo positivo
    int i=2;

    //caso o numero ja seja primo, apenas retornamos o mesmo
    if(verificaPrimo(n)){
        return n;
    }

    //transformar para o proximo primo negativo
    if(verificaNegativo(n)){
        //mudamos i, agora para o menor primo negativo, -2
        i = -2;

        //loop indefinido
        while(1){
            //caso a variavel i seja menor q n
            if(i < n){
                //verificamos ainda se o numero é primo, se sim, retornamos o mesmo, se nao, passamos para o proximo loop
                if(verificaPrimo(i)){
                    return i;
                }
            } 

            //decremento em i
            i--;
            //caso o numero i seja menor que -32000, apenas o retornamos
            if(i < -32000){
                return n;
            }
        }
    }
    
    //transformar para o proximo primo positivo
    else{
        //while indefinido
        while(1){
            //caso o numero i seja maior que n
            if(i > n){
                //verificamos ainda se o numero é primo, se sim, retornamos o mesmo, se nao, passamos para o proximo loop
                if(verificaPrimo(i)){
                    return i;
                }
            }

            //incremento em i
            i++;
            //caso o numero i seja maiorr que 32000, apenas o retornamos
            if(i > 32000){
                return n;
            }
        }
    }   
}


//funçao principal
int main(){
    //definindo o tamanho da matriz 
    int linhas, colunas;

    printf("------------------ transformando matriz inicialm em matriz so com o proximo primo ou mantendo o numero, se ja primo -------------------\n\n");
    printf("Digite a quantidade de linhas e colunas da matriz:\n> ");
    scanf("%d %d", &linhas, &colunas);

    //declaraçao da matriz com o tamanho que definimos
    int matriz[linhas][colunas], matrizResultado[linhas][colunas];

    
    //lendo matriz
    printf("Digite a matriz: \n");
    int i, j;
    //loop for de i=0 ate i < linhas, percorrendo as linhas
    for(i=0; i<linhas; i++){
        //loop for de j=0, ate j<colunas, percorrendo as colunas
        for(j=0; j<colunas; j++){
            //lendo o valor e passando para o elemento na posiçao linha(i), coluna(j)
            scanf("%d", &matriz[i][j]);
        }
    }

    //criando matriz resultado
    //loop for de i=0 ate i < linhas, percorrendo as linhas
    for(i=0; i<linhas; i++){
        //loop for de j=0, ate j<colunas, percorrendo as colunas
        for(j=0; j<colunas; j++){
            //a matriz resultado sera dada por os elementos da matriz inicial aplicada a funçao transforma primo
            matrizResultado[i][j] = transformaPrimo(matriz[i][j]);
        }
    }


    //mostrando matriz resultado
    printf("\n\nMatriz resultado : \n");
    //loop for de i=0 ate i < linhas, percorrendo as linhas
    for(i=0; i<linhas; i++){
        //loop for de j=0, ate j<colunas, percorrendo as colunas
        for(j=0; j<colunas; j++){
            //mostrando o valor da matriz resultado
            printf("%d ", matrizResultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
