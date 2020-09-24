#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//creating PI as a constant
const float PI = 3.1415;

int main(void)
{
    float radius, areaBigCircle, areaSmallCircle, grayArea;
    scanf("%f", &radius);

    areaSmallCircle = PI * pow(radius, 2);
    //the circle 2 has a radius two times greater than circle 1
    radius *= 2;
    areaBigCircle = PI * pow(radius, 2);

    //calculating gray area
    grayArea = areaBigCircle - areaSmallCircle;

    //displaying result
    printf("%f", grayArea);

    return 0;
}
