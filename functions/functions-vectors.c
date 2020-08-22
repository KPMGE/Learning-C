//program that shows the amount of even numbers and odd numbers and inverts the vector

#include <stdio.h>

int even_numbers(int n, int* vet);

int negative_numbers(int n, int* vet);

void invert_vector(int n, int* vet);

int main(void)
{
    int n, i, amount_even, amount_negative;

    printf("Type the size of vector: ");
    scanf("%d", &n);

    int vet[n];

    printf("Type the vector: ");
    for(i = 0; i < n; i++)
        scanf("%d", &vet[i]);

    amount_even = even_numbers(n, vet);
    amount_negative = negative_numbers(n, vet);
    invert_vector(n, vet);

    printf("\nEven numbers: %d\nNegative Numbers: %d\n", amount_even, amount_negative);
    printf("Inverted vector: ");
    for(i = 0; i < n; i++)
        printf("%d ", vet[i]);

    return 0;
}

int even_numbers(int n, int* vet)
{
    int i, amount = 0;

    for(i = 0; i < n; i++)
    {
        if(vet[i] % 2 == 0)
            amount++;
    }

    return amount;
}

int negative_numbers(int n, int* vet)
{
    int i, amount = 0;

    for(i = 0; i < n; i++)
    {
        if(vet[i] < 0)
            amount++;
    }

    return amount;
}

void invert_vector(int n, int* vet)
{
    int i, j, vet2[n];

    j = n - 1;

    for(i = 0; i < n; i++, j--)
        vet2[i] = vet[j];
    
    for(i = 0; i < n; i++)
        vet[i] = vet2[i];
}
