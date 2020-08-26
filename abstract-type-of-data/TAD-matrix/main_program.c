//Program that reads a matrix and shows it on screen. Using functions from 'matrix.h'

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void)
{
    int row, column, i, j;
    float value;
    Matrix* matrix;

    printf("Type the size for matrix (row, column): ");
    scanf("%d %d", &row, &column);

    matrix = create_matrix(row, column);
    
    printf("\nType the matrix:\n");
    for(i = 0 ; i < row; i++)
        for(j = 0 ; j < column; j++)
        {
            printf("Type a value: ");
            scanf("%f", &value);
            assign_matrix(matrix, i, j, value);
        }

    printf("\nYour matrix is:\n");
    for(i = 0 ; i < row; i++)
    {
        for(j = 0 ; j < column; j++)
        {
            printf("%.2f ", acess_matrix(matrix, i, j));
        }
        printf("\n");
    }

    return 0;
}
