#include <stdio.h>
int main()
{
    int i,j,temp=0,n=0,max;
   
    printf("Enter size of an array: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element of index a[%d]:",i);
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j+1]<a[j])
            {
            temp=a[j+1];
            a[j+1]=a[j];
            a[j]=temp;
            }
        }
    }
    printf("Sorted Array:");
    for (i=0;i<n;i++)
{
    printf("%d ",a[i]);
}
}
