#include <stdio.h>
int main()
{
    float P , R, T , A;
    R=8;
    printf("Enter Principal Amount:" ,P);
    scanf("%f" ,&P);
    printf("Enter time :" ,T);
    scanf("%f" ,&T);
    A= P*R*T;
    printf("%f is Amount after Compound Intrest" ,A);
    return 0;

}