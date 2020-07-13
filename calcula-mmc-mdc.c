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


//funçao que calcula o proximo primo ou mantem o mesmo numero. caso ja primo
int proximoPrimo(int num){
    //variavel com o menor primo
    int i=2;
    while(1){
        //se o numero i for maior q num
        if(i > num){
            //se sim, verificamos se e primo, se sim, retornamos
            if(verificaPrimo(i)){
                return i;
            }
        }

        i++;
    }
}


//funçao que retorna a multiplicaçao de um numero fatorado por um primo
int fatoraComPrimo(int num, int primo){
    int multi = 1, num2=num;
    while (num%primo==0){
            printf("ou");
            num /= primo;
            multi *= primo;    
    }
 
    return multi;
}


//funçao que calcula o mmc
int calculaMmc(int num1, int num2){

    //return mmc;
}


//funçao que calcula o mdc
int calculaMdc(int num1, int num2){
    
}


//funçao principal
int main(){
    int num1, num2, limnum1, limnum2, mmc, mdc;

    scanf("%d %d", &num1, &num2);

    if(num1 > num2){
        limnum1 = num2;
        limnum2 = num1;
    }else{
        limnum1 = num1;
        limnum2 = num2;
    }

    mmc = calculaMmc(limnum1, limnum2);

    printf("Mmc : %d", mmc);

    return 0;
}