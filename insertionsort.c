#include <stdio.h>
int main()
{
    int i,j,temp=0,n=0;
   
    printf("Enter size of an array: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element of index a[%d]:",i);
        scanf("%d",&a[i]);
    }

    for(i=1;i<=n-1;i++)
{
    temp=a[i];
    j=i-1;
    while (j>=0 && a[j]>temp)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=temp;
}
 printf("Sorted Array:");
for(i=0;i<n;i++)
{
    printf("%d ",a[i]);
}
return 0;
}