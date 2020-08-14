//import libraries
#include <stdio.h>
#include <math.h>

int main(void)
{
    //definition of variables
    int a, b, c;
    float delta, root1, root2;

    //reading data
    printf("Type it the values of A, B, and C of function: ");
    scanf("%d %d %d", &a, &b, &c);

    //calculating the delta
    delta = pow(b, 2) - 4*a*c;

    //if the value of delta smaller than 0, there is no roots
    if(delta < 0)
        printf("There is no roots!!");

    //calcutating roots
    else
    {
        root1 = (-b + sqrt(delta)) / 2*a;
        root2 = (-b - sqrt(delta)) / 2*a;
        printf("The value of the roots is:\nRoot1 = %.2f\n Root2 = %.2f", root1, root2);
    }

    return 0;
}
