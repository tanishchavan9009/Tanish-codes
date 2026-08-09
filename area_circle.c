#include <stdio.h>
int main()
{
    int radius, Area;
    float pi=3.14;
    printf("Enter radius of circle:" ,radius);
    scanf("%d" ,&radius);
    Area=pi*radius*radius;
    printf("%d is Area of your Circle" ,Area);
    return 0;
}