#include <stdio.h>

int main()
{
    int i, j, min, temp;
    int arr[5];

    for (i = 0; i < 5; i++)
    {
        printf("Enter Element of index %d: ", i);
        scanf("%d", &arr[i]);
    }

   
    for (i = 0; i < 4; i++)
    {
        min = i;
        for (j = i + 1; j < 5; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
