#include<stdio.h>
int main()
{
    int length, breadth ,Area;
    printf("Enter Length of Rectangle:" ,length);
    scanf("%d" ,&length);
    printf("Enter Breadth of Rectangle:" ,breadth);
    scanf("%d" ,&breadth);
    Area=length*breadth;
    printf("%d is Area of your Rectangle" ,Area);
    return 0;
}

