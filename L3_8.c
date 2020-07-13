/*
(BOCA: L3_8)
 Problema: Você subestimou o nível de conhecimento de
Padi desde a última vez que o ajudou e agora ele terminou a Lista 3
antes que você. Para provar que é mais rápido e treinar seus
conhecimentos em implementação de funções, você deve fazer um
programa que, dado o tamanho de uma matriz e seus valores, que
nunca são iguais, transforma seus valores no próximo número primo
maior que o próprio valor se o valor é positivo e menor que o próprio
valor se o valor é negativo. Caso o valor já seja primo ou se o primo
transformado extrapolar os intervalos de entrada possível, o programa
não deve fazer nenhuma mudança.

a) Seu programa deve conter a função int verificaPrimo(int n) que
retorna 1 se o número n passado como parâmetro for primo ou 0 caso
contrário.,

b) Seu programa deve conter a função int transformaPrimo(int n)
que transforma o número n passado como parâmetro no próximo maior
ou menor primo retornando o número transformado.

c) Seu programa deve conter a função int verificaNegativo(int n) que
retorna 1 se o número for negativo ou 0 caso contrário.

 Entrada: uma linha com os valores L (1 <= L <= 100) e C (1 <= C <=
100), representando o tamanho da matriz em linhas e colunas,
respectivamente. Depois, L linhas com C valores V (-32000 <= V <=
32000) cada.

 Saída: a matriz com seus valores transformados, conforme exemplo
abaixo.
*/

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
    scanf("%d %d", &linhas, &colunas);

    //declaraçao da matriz com o tamanho que definimos
    int matriz[linhas][colunas], matrizResultado[linhas][colunas];

    //lendo matriz
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