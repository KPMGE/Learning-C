/*(BOCA:L2_11) Problema: Observe a seguinte propriedade que alguns números maiores que 1000 e menores que 9999 possuem:
Número: abcd
(ab) + (cd) = (ef)
𝑒𝑓∗𝑒𝑓 = abcd
Exemplo: 3025
30+25 = 55
55∗55 = 3025
Entrada: Dois inteiros n e m (sendo n SEMPRE menor que m), contidos no intervalo (1000,9999). Ou seja, 1000 < n,m < 9999 e n<m.
Saída: Como saída, seu programa deverá exibir os números maiores que n e menores que m que satisfaçam esta propriedade, separados por uma quebra de linha.*/

#include <stdio.h>

int main(){
    //declaraçao de variaveis
    int n, n2, m, ab, cd, ef, efAoQuadrado;

    //leitura dos dados
    scanf("%d%d", &n, &m);

    //nao queremos considerar n, logo aplicamos um incremento
    n++;

    //loop for de n ate n menor que m
    for(n; n<m; n++){
        //os dois ultimos numeros sao dados pelo resto da divisao de numero por 100
        cd = n%100;
        //o valor de n2 é dado por n menos cd, logo teremos dois (00) ao final
        n2 = n-cd;
        //neste caso, para isolar os dois primeiros numeros, basta dividir por 100, cortando os 0s 
        ab = n/100;
        //ef é dado por ab + cd
        ef = ab + cd;
        //ef ao quadrado é ef * ef
        efAoQuadrado = ef*ef;

        //caso efaoquarado seja igual a n, temos um numero que satisfaz a propriedade, logo , podemos mostra-lo
        if(efAoQuadrado == n)
            printf("%d\n",efAoQuadrado);
    }

    return 0;
}
