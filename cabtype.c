#include<stdio.h>
int main()
{
    char Coustomer_name[50], CABtype[0];
    float DistanceTravelled, fare=0.0 , gst, Total_fare=0.0;
    printf("**WELCOME TO GUNGUN CAB SERVICES**\n Enter Coustomer Name: ");
    scanf("%s" ,Coustomer_name);
    printf(
           "Select the cab type from the following-\n"
           "1) M for Mini cab -> 12/km \n"
           "2) S for Sedan -> 15/km \n"
           "3) L for Luxury -> 25/km \n ->->: ");
    scanf("%s" ,CABtype);
    printf("Enter Distance Travelled (in KM)  : ");
    scanf("%f" ,&DistanceTravelled);
    
        if (CABtype[0]=='M')
        {
            printf("Congratulations You have choosen for Mini Cab" );
            fare=12*DistanceTravelled;
            gst=fare*0.05;
            Total_fare= fare+gst;
            printf("\nYour Total Fare is '%f' rupees (including GSt 5%% ) \n **THANK YOU** \n **VIST AGAIN**" ,Total_fare );
        }
        else if (CABtype[0]=='S')
        {
            printf("Congratulations You have choosen for Sedan Cab" );
            fare=14*DistanceTravelled;
            gst=fare*0.05;
            Total_fare= fare+gst;
            printf("\nYour Total Fare is '%f' rupees (including GSt 5%% ) \n **THANK YOU** \n **VIST AGAIN**" ,Total_fare  );
        }
        else if (CABtype[0]=='L')
        {
            printf("Congratulations You have choosen for Luxury Cab" );
            fare=20*DistanceTravelled;
            gst=fare*0.05;
            Total_fare= fare+gst;
            printf("\nYour Total Fare is '%f' (including GSt 5%% ) \n **THANK YOU** \n **VIST AGAIN**"  ,Total_fare );
        }
        else
        printf("**INVALID OPTION**");
    }