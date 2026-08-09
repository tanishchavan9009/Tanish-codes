#include<stdio.h>
int main()
{
    int A,B;
    printf("Enter first Number:" ,A);
    scanf("%d" ,&A);
    printf("Enter Second Number:" ,B);
    scanf("%d" ,&B);
    if (A>B)
    {
        printf("%d is greater number" ,A);
    }
    else if (A<B)
    {
    printf("%d is greater number" ,B);
    }
    else 
    {
        printf("invalid input");
    }
    return 0;
    }