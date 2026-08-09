#include <stdio.h>

int main() 
{
 int i,prn,total_mark,avg,percentage;
 int m[4];
 char name[50];
 printf("enter name of student: ");
 scanf("%s",name);
 printf("enter prn of student: ");
 scanf("%d",&prn);
 for (i=0;i<=4;i++)
 {
     printf("enter marks : \n" );
     scanf("%d",&m[i]);
   
 }
 total_mark=m[0]+m[1]+m[2]+m[3]+m[4];
printf("==========total mark of student is %d==========",total_mark);
avg=(total_mark/5);
printf("\n==========avg mark of student is %d==========",avg);

if (avg<40)
{printf("\n==========you are fail========== ",avg );}
else if (avg<55& avg>=40)
{printf("\n==========you are pass and got third division========== ",avg);}
else if (avg<65 && avg>=55)
{printf("\n==========you got second divison==========",avg);}
else if (avg<80 && avg>=65)
{printf("\n==========you got first dvision==========",avg );}
else if(avg<95 && avg>=80)
{printf("\n==========you got distinction========== ",avg);}
else if (avg<100&& avg>=95)
{printf("\n==========you are extra odinary========== ",avg );}
else
printf("error");
printf("\n=======================================================");
    return 0;
}
