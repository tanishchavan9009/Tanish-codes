#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    // The assignment requires an array. 1000 is usually enough, 
    // but 5000 is safer for large datasets.
    int weights[5000]; 
    int count = 0;
    int temp_val;
    long sum = 0;
    double average;

    // Open the file
    file = fopen("18_elephant_seal_data.txt", "r");
    
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read the file loop
    while (!feof(file)) {
        // Try to read an integer
        if (fscanf(file, "%d", &temp_val) == 1) {
            // FILTER: Real seal weights in this dataset are large (>2000).
            // This 'if' ignores the "1" or "2" from the "" tags
            // so they don't ruin your average calculation.
            if (temp_val > 2000) {
                weights[count] = temp_val;
                sum += weights[count];
                count++;
            }
        } else {
            // If fscanf fails (it found text like "source" or "["), 
            // read one character to skip it and try again.
            fgetc(file); 
        }
    }

    fclose(file);

    // Calculate and Print Average
    if (count > 0) {
        average = (double)sum / count;
        printf("Total Seals: %d\n", count);
        printf("Average Weight: %.2f\n", average);
    } else {
        printf("No valid data found.\n");
    }

    return 0;
}