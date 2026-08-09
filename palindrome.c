#include <stdio.h>

int main() 
    {
    int remainder = 0, num, reversed = 0, original;

    printf("Enter the num: ");
    scanf("%d", &num);

    original = num;

    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = num / 10;
    }

    if (original == reversed) {
        printf("num is in palindrome");
    } else {
        printf("num not in palindrome");
    }

    return 0;
}

