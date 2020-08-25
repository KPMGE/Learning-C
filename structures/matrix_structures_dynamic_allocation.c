//Program that uses a matrix with dynamic allocation where each element of matrix is a structure

#include <stdio.h>
#include <stdlib.h>

struct point
{
    float x; 
    float y;
};
typedef struct point Point;

Point** create_matrix(int rows, int columns);
void read_matrix(Point** matrix, int rows, int columns);
void print_matrix(Point** matrix, int rows, int columns);

int main(void)
{
    int rows, columns;
    Point** matrix;

    printf("Type the amount of rows and columns for matrix of Points: ");
    scanf("%d %d", &rows, &columns);

    matrix = create_matrix(rows, columns);
    read_matrix(matrix, rows, columns);
    print_matrix(matrix, rows, columns);

    return 0;
}

Point** create_matrix(int rows, int columns)
{
    int i;
    Point** matrix;

    matrix = (Point**)malloc(rows * sizeof(Point*));
    for(i = 0; i < rows; i++)
        matrix[i] = (Point*)malloc(columns * sizeof(Point));

    return matrix;
}

void read_matrix(Point** matrix, int rows, int columns)
{
    int i, j;

    for(i = 0; i < rows; i++)
        for(j = 0; j < columns; j++)
        {
            printf("Type a Point(x, y): ");
            scanf("%f %f", &matrix[i][j].x, &matrix[i][j].y);
        }
}

void print_matrix(Point** matrix, int rows, int columns)
{
    int i, j;

    printf("\nMatrix of Points:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            printf("(%.1f, %.1f) ", matrix[i][j].x, matrix[i][j].y);

        }
        printf("\n");
    }
}
