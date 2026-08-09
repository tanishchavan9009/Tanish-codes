#include <stdio.h>
#include <math.h>   // Required for sin()
#include <stdlib.h> // Required for EXIT_SUCCESS, EXIT_FAILURE

// Function Prototypes
double calculate_sine(double x);
int validate_input(double x);

int main(void) {
    double input_val;

    printf("--- Sine Calculator (Range: 0 < x < 1) ---\n");
    printf("Enter a value in radians: ");

    // 1. Input Handling: Check if the user actually entered a number
    if (scanf("%lf", &input_val) != 1) {
        fprintf(stderr, "Error: Invalid input format. Please enter a numeric value.\n");
        return EXIT_FAILURE;
    }

    // 2. Range Validation: Check logic constraints
    if (!validate_input(input_val)) {
        fprintf(stderr, "Error: Value %.4f is out of bounds.\n", input_val);
        fprintf(stderr, "Constraint: 0 < x < 1 (non-inclusive).\n");
        return EXIT_FAILURE;
    }

    // 3. Calculation & Output
    double result = calculate_sine(input_val);
    printf("Success: sin(%.4f) = %.6f\n", input_val, result);

    return EXIT_SUCCESS;
}

/**
 * Validates if the input is strictly between 0 and 1.
 * * @param x The number to check
 * @return 1 if valid, 0 if invalid
 */
int validate_input(double x) {
    // Using <= and >= ensures the range is non-inclusive (exclusive)
    if (x <= 0.0 || x >= 1.0) {
        return 0; 
    }
    return 1;
}

/**
 * Wrapper for the sine calculation.
 * * @param x The angle in radians
 * @return The sine of x
 */
double calculate_sine(double x) {
    return sin(x);
}   