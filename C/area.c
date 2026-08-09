#include <stdio.h>
#define PI 3.14159

int main(void)
{ 
    int radius;
    printf("Enter radius: ");
    scanf("%d", &radius);

    double volume = (4.0 * PI * radius * radius * radius) / 3.0;

    printf("Volume is: %.2f\n\n", volume);
    return 0;
}