#include <stdio.h>
int main()
{
    char T,C,S,o;
    float amt,gst,total;
    int qty;
    printf("Good Morning sir/madam\nOur cafe has the following menu:\nTea(80rs),Coffee(120.50rs),Sandwich(150.75rs)\n");
    printf("Enter your order(T/C/S): ");
    scanf("%c",&o);
    switch (o)
    {
         case 'T':
        case 't':
        printf("You have ordered Tea\n");
        printf("Enter the quantity: ");
        scanf("%d",&qty);
        amt=80*qty;
        gst=amt*0.05;
        total=amt+gst;
        printf("Your total amount is %f",total);
        break;

        case 'C':
        case 'c':
        printf("You have ordered Coffee\n");
        printf("Enter the quantity: ");
        scanf("%d",&qty);
        amt=120.50*qty;
        gst=amt*0.05;  
        total=amt+gst;
        printf("Your total amount is %f",total);
        break;

        case 'S':
        case 's':
        printf("You have ordered Sandwich\n");
        printf("Enter the quantity: ");
        scanf("%d",&qty);
        amt=150.75*qty;
        gst=amt*0.05;
        total=amt+gst;
        printf("Your total amount is %f",total);
        break;  

        default:
        printf("Not available krupaya karun phudchya dukanat java");
        break;
    }
    return 0;

}
