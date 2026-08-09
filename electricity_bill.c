#include <stdio.h>
int main()
{
    int Coustmer_ID;
    char Coustmer_name[50];
    float bill_amount,units;
    printf("Enter Coustmer Name: ");
    scanf("%s" ,Coustmer_name);
    printf("Enter Coustmer ID: ");
    scanf("%d" , &Coustmer_ID);
    printf("Enter total units consumed: ");
    scanf("%f", &units);

    if (units <= 100) 
    {
        bill_amount = units * 1.50;
    }
    else if (units <= 200)
    {
        bill_amount = (100 * 1.50) + ((units - 100) * 2.00);
    }
    else
    {
        bill_amount = (100 * 1.50) + (100 * 2) + ((units - 200) * 3.00);
    }
    printf("Coustmer Name: %s\n" ,Coustmer_name);
    printf("Total electricity bill: %.2f\n", bill_amount);
    return 0;
}