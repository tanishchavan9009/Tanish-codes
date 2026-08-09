#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;

    printf("Enter a value between 0 and 1 (non-inclusive): ");
    scanf("%lf", &x);

    if (x > 0.0 && x < 1.0)
    {
        double s = sin(x);
        printf("sin(%f) = %f\n", x, s);
    }
    else
    {
        printf("Error: value must be strictly between 0 and 1.\n");
    }

    return 0;
}