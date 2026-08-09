#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Initialize variables
    FILE *file;
    // Assuming a max of 10,000 data points. 
    // If the file is larger, increase this number.
    int weights[10000]; 
    int count = 0;
    int temp_weight;
    long total_weight = 0;
    double average;

    // 2. Open the file
    // Ensure the text file is in the same directory as your program
    file = fopen("18_elephant_seal_data.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // 3. Read data into the array
    printf("Reading file...\n");
    
    // fscanf returns the number of items successfully read. 
    // It returns EOF (End Of File) when done.
    while (fscanf(file, "%d", &temp_weight) == 1) {
        // Store the weight in the array
        weights[count] = temp_weight;
        count++;
        
        // Safety check to prevent array overflow
        if (count >= 10000) {
            printf("Warning: Array limit reached. Some data may be truncated.\n");
            break;
        }
    }

    fclose(file);

    // 4. Calculate Average using the array
    for (int i = 0; i < count; i++) {
        total_weight += weights[i];
    }

    if (count > 0) {
        average = (double)total_weight / count;
        
        // 5. Output results
        printf("-----------------------------\n");
        printf("Number of seals processed: %d\n", count);
        printf("Total weight: %ld\n", total_weight);
        printf("Average weight: %.2f\n", average);
        printf("-----------------------------\n");
    } else {
        printf("No data found in the file.\n");
    }

    return 0;
}