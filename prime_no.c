#include <stdio.h>

int main() {
    int i, num, n, count;
    printf("Enter the range: ");
    scanf("%d", &n);

    printf("The prime numbers between 1 and %d are: ", n);
    for (num = 2; num <= n; num++) {
        count = 0;

        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                count++;
                break; 
            }
        }

        if (count == 0) {
            printf("%d ", num);
        }
    }

    printf("\n");
    return 0;
}