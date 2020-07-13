/*
(BOCA:L3_9) 
Problema: Você e seu amigo estão desenvolvendo um projeto de Iniciação Científica, no qual consiste na criação de um dispositivo de análises da chuva de determinada região. O dispositivo analisa, através de uma nova tecnologia, o pH das gotas de chuva de uma área. Para demonstrar o projeto para outros colegas, você precisa implementar um programa que mostra as estatísticas da chuva de uma região, dados a área da região em metros quadrados e a densidade de gotas de chuva (quantas gotas de chuva caem em 1 metro quadrado a cada 1 segundo) e o tempo em segundos que o dispositivo analisou o local.

a) Seu programa deve conter a função int verificapH(float pH) que retorna 0 para pH neutro, 1 para ácido e 2 para básico. 

b) Seu programa deve conter a função int verificaGotaChuvaAcida(float pH) que retorna verdadeiro se a gota for considerada chuva ácida (pH menor que 5.7) e falso caso contrário.

c) Seu programa deve conter a função float porcentagem(float total, float valor) que retorna a porcentagem de um valor em relação ao número total.

d) Seu programa deve conter a função void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal) que imprime os resultados conforme formatação mostrada abaixo. Atenção: o pH considerado neutro é igual a 7.00; ácido é menor que 7.00; básico é maior que 7.00. Todas as impressões de float devem ser com precisão de 2 casas decimais.

 Entrada: a entrada do seu programa deve conter uma linha com três números inteiros: a área A (0 <= A <= 50) da região a ser analisada em metros quadrados, a densidade D (0 <= D <= 50) de gotas de chuva por metro quadrado em 1 segundo, e o tempo T (0 <= T <= 12) que o dispositivo analisou o local em segundos. Em seguida, seu programa deverá ler um valor float P (0.00 <= P <= 14.00) (você deve considerar as entradas sempre com 2 casas decimais de precisão) para cada gota de chuva que caiu no tempo e região dados representando o pH da água.

 Saída: a saída do seu programa deverá imprimir uma linha com a quantidade de gotas com pH ácido, básico e neutro analisadas pelo dispositivo, o pH mais ácido, o pH mais básico e o pH mais neutro. Também deve imprimir outra linha com uma mensagem sobre a chuva nas condições dadas – se foi considerada ácida (75.00% ou mais das gotas com pH menor que 5.70), normal (75.00% ou mais das gotas com pH maior ou igual 5.70) ou com indícios de chuva ácida caso contrário; essa linha deve ser seguida da porcentagem de gotas com pH menor que 5.70 e a porcentagem de gotas com pH igual ou maior que 5.70. Caso o dispositivo não avalie nenhuma gota, a saída do seu programa deve imprimir somente a mensagem “Nenhuma gota foi avaliada”. Atenção às formatações abaixo.
*/

//importaçao de bibliotecas
#include <stdio.h>

//funçao que retorna 0 para pH neutro, 1 para ácido e 2 para básico
int verificapH(float pH){
    if(pH == 7){
        return 0;
    }
    else if(pH < 7){
        return 1;
    }
    else{
        return 2;
    }
}


//funçao que retorna verdadeiro se a gota for considerada chuva ácida (pH menor que 5.7) e falso caso contrário
int verificaGotaChuvaAcida(float pH){
    if(pH < 5.7){
        return 1;
    }else{
        return 0;
    }
}


//funçao que retorna a porcentagem de um valor em relação ao número total
float porcentagem(float total, float valor) {
    float porcentagem;

    porcentagem = (valor*100)/total;

    return porcentagem;
}


//funçao que imprime os resultados conforme formatação
void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal){

}


//funçao principal
int main(){
    //variaveis usadas 
    int area, densidade, tempo;
    float pH;

    //leitura de dados
    scanf("%d %d %d %.2f", &area, &densidade, &tempo, &pH);

    return 0;
}