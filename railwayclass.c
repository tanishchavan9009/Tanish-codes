#include<stdio.h>
int main()  
{
    char cls;
    int seat_no,qty;
    float ticket_price, total_price;
    printf("Enter your seat number: ");
    scanf("%d", &seat_no);
    printf("Enter the class you want to travel in (G/A-AC/S): ");
    scanf(" %c", &cls); // Added space before %c to consume any leftover newline
    printf("Enter Quantity: " ,qty);
    scanf("%d" ,&qty);
    switch(cls)
    {
        case 'G':
        case 'g':
        ticket_price = 500*qty;
            printf("You have chosen General Class\n");
            printf("Amenities: Complimentary meals, Avg sponge seats\n");
            printf("Your ticket price is: %f\n", ticket_price);
            total_price = (ticket_price + (ticket_price * 0.18)); // Including 18% GST
            printf("Total price after including 18%% GST: %f\n", total_price);
            break;

        case 'A':
        case 'a':
            ticket_price = 1500*qty;
            printf("You have chosen AC Class\n");
            printf("Amenities: AC room, mid-day meals,cusion seats\n");
            printf("Your ticket price is: %f\n", ticket_price);
            total_price = (ticket_price + (ticket_price * 0.18)); // Including 18% GST
            printf("Total price after including 18%% GST: %f\n", total_price);
            break;
            
        case 'S':
        case 's':
            ticket_price = 1000*qty;
            printf("You have chosen Sleeper Class\n");
            printf("Amenities: Sleeping berths, Basic meals\n");
            printf("Your ticket price is: %f\n", ticket_price);
            total_price = (ticket_price + (ticket_price * 0.18)); // Including 18% GST
            printf("Total price after including 18%% GST: %f\n", total_price);
            break;
        default:
            printf("Invalid class selection. Please choose G, A, or S.\n");
    }
    
}