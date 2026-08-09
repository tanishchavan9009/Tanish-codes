#include <stdio.h>
struct record
{
    char name[20],branch[20],div[2];
    int prn;
    float perc;
};
int main()
{
 int i,n,j;
struct record record[i];

 printf("Enter the no of records you want to maintain: ");
 scanf("%d",&n);

 for(i=1;i<=n;i++)
 {
    printf("==========RECORD [%d]==========",i);
    printf("\nEnter Name of Student: ");
    scanf("%s",record[i].name);
    printf("Enter Prn of Student: ");
    scanf("%d",&record[i].prn);
    printf("Enter div of Student: ");
    scanf("%s",record[i].div);
    printf("Enter Branch of Student: ");
    scanf("%s",record[i].branch);
    printf("Enter Percentage of Student: ");
    scanf("%f",&record[i].perc);
 }
  for (i = 1; i < n; i++)
    {
        struct record 
        temp = record[i]; 
        j = i - 1;
        while (j >= 0 && record[j].perc < temp.perc) 
        {
            record[j + 1] = record[j]; 
            j--;
        }
        record[j + 1] = temp;
    }
 for(i=0;i<n;i++)
 {
    printf("==========SORTED DETAILS OF STUDENTS [%d]==========",i);
    printf("\nName: %s, \nPRN: %d,\n Div: %s, \nBranch: %s,\n Percentage: %.2f\n", record[i].name, record[i].prn, record[i].div, record[i].branch, record[i].perc);
 }
 return 0;
 
 }