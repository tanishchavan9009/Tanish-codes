II quotes " " in printf.

Correct:

printf("sin( %lf ) = %lf \t", interval, abs(sin(interval)));


Wrong function for floating-point absolute:

abs() works only on integers.

sin(interval) returns double.

Use fabs() for absolute value of doubles:

fabs(sin(interval))


Optional: Add \n inside the loop if you want each output on a new line. Otherwise, all outputs will be on the same line.

✅ Corrected Code
#include <stdio.h>
#include <math.h> /* has sin(), abs(), and fabs() */

int main(void)
{ 
    double interval;
    int i;

    for(i = 0; i < 30; i++)
    {
        interval = i / 10.0;
        printf("sin( %lf ) = %lf \t", interval, fabs(sin(interval)));
    }

    printf("\n+++++++\n");
    return 0;
}   