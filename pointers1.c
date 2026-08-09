#include <stdio.h>
int main()
{
    int i,j,n,x=0;
    printf("Enter no of rows: ");
    scanf("%d",&n);

    for (i=0;i<=n;i++)
    {
        for (j=0;j<i;j++)
        {
            x=i+j;
            printf("%d");
        }
        printf("\n");
    }
    return 0;
}
