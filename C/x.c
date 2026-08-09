#include <stdio.h>
#include <math.h>

/*
 * Program: Sine and Cosine Table
 * This program prints a table of sine and cosine values
 * for values between 0 and 1 (exclusive) in steps of 0.1.
 * Author: [Your Name]
 */

void printSinCosTable(void);

int main(void)
{
    // Print the sine and cosine table
    printSinCosTable();
    return 0;
}

/*
 * Function: printSinCosTable
 * --------------------------
 * Prints a table of sine and cosine values for numbers
 * between 0 and 1 (exclusive).
 *
 * Uses a step of 0.1 for demonstration.
 */
void printSinCosTable(void)
{
    double x;
    double step = 0.1;

    // Print table header
    printf("%-10s %-10s %-10s\n", "Value", "sin(x)", "cos(x)");
    printf("---------------------------------\n");

    // Loop through values from step to less than 1
    for (x = step; x < 1.0; x += step)
    {
        printf("%-10.2f %-10.6f %-10.6f\n", x, sin(x), cos(x));
    }

    printf("---------------------------------\n");
}




