#include <stdio.h>
#include <assert.h>

//
// Função mmc
//
int mmc(int num1, int num2) {

    int mmc, aux, i;

    for (i = 2; i <= num2; i++) {
        aux = num1 * i;
        if ((aux % num2) == 0) {
            mmc = aux;
            i = num2 + 1;
        }
    }
    return mmc;
}

//
// Função mdc
//
int mdc(int num1, int num2) {

    int resto;

    do {
        resto = num1 % num2;

        num1 = num2;
        num2 = resto;

    } while (resto != 0);

    return num1;
}


int main() {
    int num1, num2, Mmc, Mdc;

    assert(3 == mdc(24, 9));
    assert(10 == mdc(30, 20));

    scanf("%d %d", &num1, &num2);

    Mmc = mmc(num1 , num2);
    Mdc = mdc(num1, num2);

    printf("%d %d", Mmc, Mdc);
    return 0;
}
