//Program that uses matrices where each element is a structure

#include <stdio.h>

struct point 
{
    float x;
    float y;
};
typedef struct point Point;

void read_matrix(Point matrixPoints[][3]);
void print_matrix(Point matrixPoints[][3]);

int main(void)
{
    Point matrixPoints[3][3];

    read_matrix(matrixPoints);
    print_matrix(matrixPoints);

    return 0;
}

void read_matrix(Point matrixPoints[][3])
{
    int i, j;

    printf("Matrix 3x3:\n");
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            printf("Type a point: ");
            scanf("%f %f", &matrixPoints[i][j].x, &matrixPoints[i][j].y);
        }
}

void print_matrix(Point matrixPoints[][3])
{
    int i, j;

    printf("\nMatrix typed:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("(%.1f %.1f) ", matrixPoints[i][j].x, matrixPoints[i][j].y);
        }
        printf("\n");
    }
}
