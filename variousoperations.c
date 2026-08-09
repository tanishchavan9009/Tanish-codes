#include <stdio.h>
int main()  
{
    char x;
    printf("Enter the operation you want to perform (+, -, *, /): ");
    scanf("%c",&x);
    int a,b;
    printf("Enter 1ST integer: ");
    scanf("%d",&a);
    printf("Enter 2ND integer: "); 
    scanf("%d",&b);


    if (x=='+')
    {
        printf("The sum is %d" ,a+b);
    }
    else if (x=='-')
    {
        printf("The difference is %d" ,a-b);
    }
    else if (x=='*')
    {
        printf("The product is %d" ,a*b);
    }
    else if (x=='/')
    {
       printf("The quotient is %d" ,a/b);
    }
    else
    {
        printf("Invalid operation. Please enter one of +, -, *, /.");
    }
    return 0;
}