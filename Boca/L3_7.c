#include <stdio.h>
#include <math.h>

int area(int x1, int y1, int x2, int y2);
int area_total(int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2);

int main(void)
{
    int areaFinal;
    int r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2;

    scanf("%d %d %d %d", &r1_x1, &r1_y1, &r1_x2, &r1_y2);
    scanf("%d %d %d %d", &r2_x1, &r2_y1, &r2_x2, &r2_y2);

    areaFinal = area_total(r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2);

    printf("RESP:%d", areaFinal);

    return 0;
}

int area(int x1, int y1, int x2, int y2)
{
    int aresta1, aresta2, areaRetangulo;

    aresta1 = y2 - y1;
    aresta2 = x2 - x1;
    areaRetangulo = aresta1 * aresta2;

    return areaRetangulo;
}

int area_total(int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2)
{
    float area1, area2, total;

    area1 = area(r1_x1, r1_y1, r1_x2, r1_y2);
    area2 = area(r2_x1, r2_y1, r2_x2, r2_y2);
    total = area1 + area2;

    return total;
}
