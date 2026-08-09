#include<stdio.h>
int main()
{
    int i, gcd,num1 , num2;
    printf("Enter Two number of which you want to find GCD: ");
    scanf("%d %d" ,&num1 ,&num2);

    for (i=2;i<=num1 && i<=num2;i++)
    {
        if (num1%i==0 && num2%i==0)
        {
            gcd=i;
            break;
        }
    }
    printf("GCD of a num %d and %d is %d" ,num1 ,num2,gcd);

    return 0;
}