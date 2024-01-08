#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Include the string.h header for strtok

int main() {
    // Declare variables
    char input[100];
    int num, total = 0, count = 0;

    // Prompt user for input
    printf("Enter a sequence of integers separated by spaces: ");

    // Read a line of input
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Process each integer in the input
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Convert the token to an integer
        num = atoi(token);

        // Update total and count
        total += num;
        count++;

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Check if there are no integers in the sequence
    if (count == 0) {
        printf("No integers found in the sequence.\n");
        return 0;
    }

    // Calculate the average
    double average = (double)total / count;

    // Print the results
    printf("Number of integers: %d\n", count);
    printf("Average of integers: %.3lf\n", average);

    return 0;
}
